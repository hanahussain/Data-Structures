#ifndef DIJKSTRA_H_EXISTS
#define DIJKSTRA_H_EXISTS

class dijkstra{
	private:
		bool visited[16]; //whether each vertex has been visited or not
		double dist[16]; //tracks the shortest known distance from source A to each vertex

	public:
		dijkstra();
		int minDist(); //finds the unvisited index with the shortest distance
		void initializeArrays(); //initializes the values of member arrays
		double shortestPath(double graph[16][16]); //updates dist based on dijkstra's algorithm, and returns dist[15] (aka shortest path between source A and destination B
		void path(double graph[16][16]);
};

#endif
