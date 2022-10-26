#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
#include <cstdlib>
#include <utility>
#include <queue>
#include <stack>
#include "graph.h"


int main()
{
	Graph<int> ob{ {0, 1},{2, 3},{4, 5},{6, 7} };
	ob.insert_edge(0, 2);
	ob.insert_edge(1, 3);
	ob.insert_edge(1, 4);
	ob.insert_edge(2, 6);
	ob.insert_edge(3, 5);
	ob.insert_edge(5, 6);
	Graph<int> ob2 = ob;
	std::cout << ob2;
	//ob.insert_vertex(8);
	//ob.insert_edge(7, 8);
	//ob.erase_vertex(0);
	//ob.erase_edge(3, 5);
	//std::cout << ob.get_number_of_vertex();
	//std::cout << ob.find_path(0, 7);
	//std::cout << ob;
	//ob.DFS(0);
	//ob.BFS(0);
	
}