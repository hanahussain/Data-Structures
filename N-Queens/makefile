nQueens: main.o nQueens.o
	g++ main.o nQueens.o -o nQueens

main.o: main.cpp nQueens.h
	g++ -c main.cpp

nQueens.o: nQueens.cpp nQueens.h
	g++ -c nQueens.cpp

clean:
	rm *.o
	rm nQueens

run: nQueens
	./nQueens
