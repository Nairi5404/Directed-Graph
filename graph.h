#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
class Graph
{
public:
	Graph() = default;
	Graph(const Graph&);
	Graph& operator=(const Graph&);
	Graph(std::initializer_list<std::pair<T, T>>);
	Graph(Graph&&);
	Graph& operator=(Graph&&);
	~Graph() {};

public:
	bool operator==(const Graph&) const;
	bool operator!=(const Graph&) const;
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Graph<U>&);

public:
	void insert_vertex(T);
	void insert_edge(T, T);
	std::vector<T> get_vertex_set();
	std::vector<T> get_edge_set();
	void erase_vertex(T);
	void erase_edge(T, T);
	int get_number_of_vertex() const;
	int find_path(T vertex1, T vertex2);
	void DFS(T start);
	void BFS(T start);

private:
	std::unordered_map<T, std::list<T> > adj;
	std::unordered_map<T, bool> visited;
};

template <typename T>
Graph<T>::Graph(const Graph& ob)
{
	adj = ob.adj;
	visited = ob.visited;
}

template <typename T>
Graph<T>& Graph<T>::operator=(const Graph& ob)
{
	if (this == &ob) {
		return *this;
	}
	adj = ob.adj;
	visited = ob.visited;
	return *this;
}

template <typename T>
Graph<T>::Graph(std::initializer_list<std::pair<T, T>> vertex)
{
	for (auto it = vertex.begin(); it != vertex.end(); ++it)
	{
		insert_edge(it->first, it->second);
	}
}

template <typename T>
Graph<T>::Graph(Graph&& ob)
{
	adj = std::move(ob.adj);
	visited = std::move(ob.visited);
}

template <typename T>
Graph<T>& Graph<T>::operator=(Graph&& ob)
{
	if (!ob.adj.empty())
	{
		adj = std::move(ob.adj);
	}

	if (!ob.visited.empty())
	{
		visited = std::move(ob.visited);
	}
	return *this;
}

template <typename T>
bool Graph<T>::operator==(const Graph& ob) const {
	return adj == ob.adj;
}

template <typename T>
bool Graph<T>::operator!=(const Graph& ob) const {
	return !(adj == ob.adj);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Graph<T>& ob)
{
	for (auto it = ob.adj.begin(); it != ob.adj.end(); ++it)
	{
		os << it->first << " ";
	
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			os << *it2 << " ";
		}
		os << std::endl;
	}
	return os;
}

template <typename T>
void Graph<T>::insert_vertex(T id)
{
	adj.insert(std::pair<T, std::list<T> >(id, {}));
}

template <typename T>
void Graph<T>::insert_edge(T vertex1, T vertex2)
{
	if (adj.find(vertex1) != adj.end() && adj.find(vertex2) != adj.end())
	{
		adj[vertex1].push_back(vertex2);
	}
	else if (adj.find(vertex1) == adj.end() && adj.find(vertex2) != adj.end())
	{
		insert_vertex(vertex1);
		adj[vertex1].push_back(vertex2);
	}
	else if (adj.find(vertex1) != adj.end() && adj.find(vertex2) == adj.end())
	{
		insert_vertex(vertex2);
		adj[vertex1].push_back(vertex2);
	}
	else
	{
		insert_vertex(vertex1);
		insert_vertex(vertex2);
		adj[vertex1].push_back(vertex2);
	}
}

template <typename T>
std::vector<T> Graph<T>::get_vertex_set()
{
	std::vector<T> vec;
	for (auto& it : adj)
	{
		vec.push_back(it.first);
	}
	return vec;
}

template <typename T>
std::vector<T> Graph<T>::get_edge_set()
{
	std::vector<T> vec;
	for (auto it = adj.begin(); it != adj.end(); ++it)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			vec.push_back(*it2);
		}
	}
	return vec;
}

template <typename T>
void Graph<T>::erase_vertex(T vertex)
{
	if(adj.find(vertex) == adj.end()) 
	{
		std::cout << "This Value Not Found";
		return;
	}
	adj.erase(vertex);

	for (auto it = adj.begin(); it != adj.end(); ++it)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end();)
		{
			if (*it2 == vertex)
			{
				it2 = it->second.erase(it2);
			}
			else
			{
				++it2;
			}
		}
	}
}

template <typename T>
void Graph<T>::erase_edge(T vertex1, T vertex2)
{
	for (auto it = adj[vertex1].begin(); it != adj[vertex1].end();)
	{
		if (*it == vertex2)
		{
			it = adj[vertex1].erase(it);
		}
		else
		{
			++it;
		}
	}
}

template <typename T>
int Graph<T>::find_path(T vertex1, T vertex2)
{
	int count{};

	if (!adj.empty())//BFS traversal
	{
		visited[vertex1] = true;
		std::queue<int> q;
		if (adj.find(vertex1) != adj.end() && adj.find(vertex2) != adj.end())
		{
			q.push(vertex1);
		}
		while (!q.empty())
		{
			int front = q.front();
			if (front == vertex2)
			{
				break;
			}
			++count;
			q.pop();

			for (auto it = adj[front].begin(); it != adj[front].end(); ++it)
			{
				if (!visited[*it])
				{
					visited[*it] = true;
					q.push(*it);
				}
			}
		}
	}
	return count;
}

template <typename T>
int Graph<T>::get_number_of_vertex() const
{
	return adj.size();
}


template <typename T>
void Graph<T>::DFS(T start)
{
	if (adj.find(start) == adj.end())
	{
		std::cout << "Invalid Vertex";
		return;
	}

	if (!visited.empty())
	{
		for (auto& it : visited)
		{
			if (it.second)
			{
				it.second = false;
			}
		}
	}
	if (!adj.empty())
	{
		std::stack<int> s;
		if (adj.find(start) != adj.end())
		{
			s.push(start);
		}
		while (!s.empty())
		{
			int top = s.top();
			s.pop();

			if (!visited[top])
			{
				std::cout << top << " ";
				visited[top] = true;
			}

			for (auto it = adj[top].begin(); it != adj[top].end(); ++it)
			{
				if (!visited[*it])
				{
					s.push(*it);
				}
			}
		}
		/*visited[start] = true;//recursive
		std::cout << start << " ";

		for (auto it = adj[start].begin(); it != adj[start].end(); ++it)
		{
			if (!visited[*it]) {
				DFS(*it);
			}
		}*/
	}
}

template <typename T>
void Graph<T>::BFS(T start)
{
	if (adj.find(start) == adj.end())
	{
		std::cout << "Invalid Vertex";
		return;
	}

	if (!visited.empty())
	{
		for (auto& it : visited)
		{
			if (it.second) {
				it.second = false;
			}
		}
	}
	if (!adj.empty())
	{
		visited[start] = true;
		std::queue<int> q;
		if (adj.find(start) != adj.end())
		{
			q.push(start);
		}
		while (!q.empty())
		{
			int front = q.front();
			std::cout << front << " ";
			q.pop();

			for (auto it = adj[front].begin(); it != adj[front].end(); ++it)
			{
				if (!visited[*it])
				{
					visited[*it] = true;
					q.push(*it);
				}
			}
		}
	}
}

#endif