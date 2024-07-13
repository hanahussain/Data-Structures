BST: main.o BST.o Node.o
	g++ main.o BST.o Node.o -o BST

main.o: main.cpp BST.h Node.h
	g++ -c main.cpp

BST.o: BST.cpp BST.h Node.h
	g++ -c BST.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *.o
	rm BST

run: BST
	./BST
