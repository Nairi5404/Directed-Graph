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
	/*Graph ob{1,2,3,4,5,6,7};
	ob.insert_edge(1, 2);
	ob.insert_edge(1, 4);
	ob.insert_edge(1, 5);
	ob.insert_edge(2, 7);//asfsgd
	ob.insert_edge(2, 6);
	ob.insert_edge(2, 3);*/
	Graph<int> ob;// { {0, 1}, { 2,3 }, { 4,5 }, { 6,7 } };
	ob.insert_edge(0, 1);
	ob.insert_edge(0, 2);
	ob.insert_edge(1, 3);
	ob.insert_edge(1, 4);
	ob.insert_edge(2, 3);
	ob.insert_edge(2, 6);
	ob.insert_edge(3, 5);
	ob.insert_edge(4, 5);
	ob.insert_edge(5, 6);
	//std::cout << ob;
	//ob.DFS(20);
	//ob.erase_edge(1,4);
	//std::cout << std::endl;
	//ob.DFS(0);
	//ob.BFS(20);
	//std::cout << ob;
	/*Graph ob2 = ob;
	ob2.insert_edge(0, 1);
	ob2.insert_edge(0, 2);
	ob2.insert_edge(1, 2);
	ob2.DFS(0);*/
	//std::cout << ob.find_path(0, 5);
	//std::cout << ob.get_number_of_vertex(0);
	//ob.get_vertex_set(0);
	//ob.DFS(0);
	//ob.BFS(0);
}