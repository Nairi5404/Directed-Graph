<h1><b> Directed Graph </b></h1>
<hr>
<h1><b>What is Graph in Data Structure and Algorithms?</b></h1>
  
<h3><i>A Graph is a non-linear data structure consisting of vertices and edges. The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(E, V)</i></h3>

 <h1><b>Components of a Graph</b></h1>
  
  <i><h3>Vertices: Vertices are the fundamental units of the graph. Sometimes, vertices are also known as vertex or nodes. Every node/vertex can be labeled or unlabelled.
  
Edges: Edges are drawn or used to connect two nodes of the graph. It can be ordered pair of nodes in a directed graph. Edges can connect any two nodes in any possible way. There are no rules. Sometimes, edges are also known as arcs. Every edge can be labeled/unlabelled.
  
Graphs are used to solve many real-life problems. Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network. Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender, locale etc.</i></h3>

<h1><b>Graph and its representations</b></h1>

<h3><i>The following two are the most commonly used representations of a graph. 
1. Adjacency Matrix 
2. Adjacency List 
There are other representations also like, Incidence Matrix and Incidence List. The choice of graph representation is situation-specific. It totally depends on the type of operations to be performed and ease of use.</i></h3>

<h2><b>Adjacency Matrix:</b></h2>  
<h3><i>Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.</i></h3>

![adjmatexample](https://user-images.githubusercontent.com/99535791/198031844-da84dea1-d588-46f3-9f1b-8760743eabf5.png)


<h2><b>Adjacency List:</b></h2>
<h3><i>An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph.</i></h3>

![8 an-adjacency-list-for-the-directed-graph](https://user-images.githubusercontent.com/99535791/198031535-b0b1c606-c70d-45b1-8b6a-bc7cfcc1596a.png)

<h1><b> Directed Graph </b></h1>
  
<h3><i>A directed graph, also called a digraph, is a graph in which the edges have a direction. This is usually indicated with an arrow on the edge; more formally, if v and w are vertices, an edge is an unordered pair {v,w}, while a directed edge, called an arc, is an ordered pair (v,w) or (w,v). The arc (v,w) is drawn as an arrow from v to w. If a graph contains both arcs (v,w) and (w,v), this is not a "multiple edge'', as the arcs are distinct. It is possible to have multiple arcs, namely, an arc (v,w) may be included multiple times in the multiset of arcs. As before, a digraph is called simple if there are no loops or multiple arcs.

We denote by E−v the set of all arcs of the form (w,v), and by E+v the set of arcs of the form (v,w). The indegree of v, denoted d−(v), is the number of arcs in E−v, and the outdegree, d+(v), is the number of arcs in E+v. If the vertices are v1,v2,…,vn, the degrees are usually denoted d−1,d−2,…,d−n and d+1,d+2,…,d+n. Note that both ∑ni=0d−i and ∑ni=0d+i count the number of arcs exactly once, and of course ∑ni=0d−i=∑ni=0d+i. A walk in a digraph is a sequence v1,e1,v2,e2,…,vk−1,ek−1,vk such that ek=(vi,vi+1); if v1=vk, it is a closed walk or a circuit. A path in a digraph is a walk in which all vertices are distinct. It is not hard to show that, as for graphs, if there is a walk from v to w then there is a path from v to w.
.</i></h3>

![Tarjans-algo](https://user-images.githubusercontent.com/99535791/198021643-5ced38c5-d533-48af-ab87-ac836d953fe2.png)

<h1><b> Adding a Vertex in the Graph: </b></h1>

<h3><i>Adding a Vertex in the Graph: To add a vertex in the graph, the adjacency list can be iterated to the place where the insertion is required and the new node can be created using linked list implementation.
  
![maxresdefault](https://user-images.githubusercontent.com/99535791/198036596-42f0fd6a-1f49-4ed7-8c79-315de7f1a23d.jpg)

<h1><b>Removing a Vertex in the Graph:</b></h1>

<h3><i>To delete a vertex in the graph, iterate through the list of each vertex if an edge is present or not. If the edge is present, then delete the vertex in the same way as delete is performed in a linked list.<i><h3>

![maxresdefault](https://user-images.githubusercontent.com/99535791/198038463-e5329800-ed2f-42fe-81cd-a6fafeeb7520.jpg)

  <h1><b>Time Complexity</b></h1>
  
  ![P8UiR](https://user-images.githubusercontent.com/99535791/198043751-8edbb14a-2256-4677-afa5-8a1adbd0c854.png)

  
