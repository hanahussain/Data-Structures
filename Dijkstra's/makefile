dijkstra: main.o dijkstra.o
	g++ main.o dijkstra.o -o dijkstra

main.o: main.cpp dijkstra.h
	g++ -c main.cpp

dijkstra.o: dijkstra.cpp dijkstra.h
	g++ -c dijkstra.cpp

clean:
	rm *.o
	rm dijkstra

run: dijkstra
	./dijkstra
