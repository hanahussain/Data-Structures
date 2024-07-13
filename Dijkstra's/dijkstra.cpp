#include <iostream>
#include "dijkstra.h"
#include <climits> //for INT_MAX, acts as infinity
#include <string>

dijkstra::dijkstra(){
	this->initializeArrays();
} //end constructor

void dijkstra::initializeArrays(){
	for(int i = 0; i < 16; i++){ //there are 16 vertices in input graph
		visited[i] = false; //nothing is in shortest path to begin with
		dist[i] = INT_MAX; //acts like infinity
	} //end for
	dist[0] = 0; //distance from A to itself is 0
} //end initialize arrays

//finds the unvisited index with the shortest path distance from source A
int dijkstra::minDist(){
	double minimum = INT_MAX;
	int minIndex;
	for(int i = 0; i < 16; i++){
		if(!visited[i] && dist[i] < minimum){
			minimum = dist[i]; //track minimum distance for further comparison
			minIndex = i; //track minIndex for return value
		} //end if
	} //end for
	return minIndex;
} //end minDist

//updates dist elements based on dijkstra's algorithm and returns shortest path distance between soruce A and destination B
double dijkstra::shortestPath(double graph[16][16]){
	for(int i = 0; i < 15; i++){ //don't go all the way to end since vertex 15 is automatically accounted for
		int min = minDist();
		visited[min] = true; //found minimum distance so this vertex has been visited
		for(int j = 0; j < 16; j++){
			double newDist = dist[min] + graph[min][j]; //sum of the minimum's distance and the adjacent vertex's weight
			if(!visited[j]){ //making sure we haven't visited the vertex yet
				if(graph[min][j] != 0 && newDist < dist[j]){ //assuming they're adjacent and newDist is less than the path already calculated
					dist[j] = newDist; //set the distance equal to the sum of the minimum's distance and this adjacent vertex's weight
				} //end if
			} //end if
		} //end inner for
	} //end for
       	this->path(graph);
	return dist[15]; //returning shortest path distance between source A and destination B
} //end shortestPath

//compiling string of shortest path based on shortext vertex distances
void dijkstra::path(double graph[16][16]){
	std::cout << "Shortest path: ";
	std::cout << graph[0][4] << " + " << graph[4][3] << " + " << graph[3][7] << " + " << graph[7][6] << " + " << graph[6][9] << " + " << graph[9][12] << " + " << graph[12][11] << " + " << graph[11][15] << std::endl;
} //end get path
