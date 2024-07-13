#include "dijkstra.h"
#include <iostream>

int main(){
	dijkstra d;
	
	//representing graph as adjacency vertex of adjacent distances
	/*
	 * I labeled A as vertex/index 0. A has 0.32 distance from vertex 1, 0.4 dist from vertex 4 and is not adjacent to anything else (0 dist)
	 * vertex 1, which I labeled as the top vertex from A, has 0.32 dist from A (vertex 0), 0.4 from the vertex 2 (index 1 in this case) and is not adjacent to anything else (0 dist)
	 * vertex 2, which is to the left of vertex 1, has 0.4 dist from 1, 0.08 dist from 3, and 0.2 dist from 8
	 * vertex 3, which is south of vertex 2, has 0.08 dist from 2, 0.1 dist from 4 and 0.2 dist from 7
	 * vertex 4, south of vertex 3, has 0.4 dist from A/0, 0.1 dist from 3 and 0.2 dist from 5
	 * vertex 5, left of vertex 4, has 0.2 dist from 4, 0.28 dist from 6 and 0.1 dist from 7
	 * vertex 6, northwest adjacent of 5, has 0.28 dist from 5, 0.15 dist from 7 and 0.25 dist from 9
	 * vertex 7, right of 6, has 0.2 dist from 3, 0.1 dist from 5, 0.15 dist from 6 and 0.05 dist from 8
	 * vertex 8, north of 7, has 0.2 dist from 2, 0.05 dist from 7 and 0.35 dist from 9
	 * vertex 9, left of 8, has 0.25 dist from 6, 0.35 dist from 8, 0.3 dist from 10&12, and 0.2 dist from 13
	 * vertex 10, northwest adjacent of 9, has 0.3 dist from 9 and 0.45 dist from 11
	 * vertex 11, north of 10, has 0.45 dist from 10, 0.05 dist from 12 and 0.3 dist from B/15
	 * vertex 12, right of 11, has 0.3 dist from 9, 0.05 dist from 11, and 0.2 dist from 13
	 * vertex 13, right of 12, has 0.2 dist from 9 and 0.2 dist from 12
	 * vertex 14, north of 12, has 0.28 dist from 12 and 0.2 dist from 15
	 * vertex B/15, left of 14, has 0.3 dist from 11 and 0.2 dist from 14 and is not adjacent to anything else (0 dist)
	 * */
	double graph[16][16] = { { 0, 0.32, 0, 0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //source A/vertex 0 as described above
		              { 0.32, 0, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //vertex 1
			      { 0, 0.4, 0, 0.08, 0, 0, 0, 0, 0.2, 0, 0, 0, 0, 0, 0, 0}, //vertex 2
			      { 0, 0, 0.08, 0, 0.1, 0, 0, 0.2, 0, 0, 0, 0, 0, 0, 0, 0}, //vertex 3
		              { 0.4, 0, 0, 0.1, 0, 0.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //vertex 4
			      { 0, 0, 0, 0, 0.2, 0, 0.28, 0.1, 0, 0, 0, 0, 0, 0, 0, 0},	//vertex 5
			      { 0, 0, 0, 0, 0, 0.28, 0, 0.15, 0, 0.25, 0, 0, 0, 0, 0, 0}, //vertex 6
			      { 0, 0, 0, 0.2, 0, 0.1, 0.15, 0, 0.05, 0, 0, 0, 0, 0, 0, 0}, //vertex 7
			      { 0, 0, 0.2, 0, 0, 0, 0, 0.05, 0, 0.35, 0, 0, 0, 0, 0, 0}, //vertex 8
			      { 0, 0, 0, 0, 0, 0, 0.25, 0, 0.35, 0, 0.3, 0, 0.3, 0.2, 0, 0}, //vertex 9
			      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.3, 0, 0.45, 0, 0, 0, 0}, //vertex 10
			      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.45, 0, 0.05, 0, 0, 0.3}, //vertex 11
			      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.3, 0, 0.05, 0, 0.2, 0.28}, //vertex 12
			      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.2, 0, 0, 0.2, 0, 0, 0}, //vertex 13
			      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.28, 0, 0, 0.2}, //vertex 14
	                      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.3, 0, 0, 0.2, 0} }; //destination B/vertex 15 as described above

	double total = d.shortestPath(graph);
	std::cout << "Shortest path distance: " << total << std::endl;
} //end main
