#include "Node.h"
#include "BST.h"
#include <cstddef>
#include <iostream>

int main(){
	BST b;
	//Node ro;
	Node* rootPtr = b.makeBST(0, 14);
	std::cout << "BST from given array:\n";
	b.printTree(rootPtr);
	int k = b.determineK();
	int smallest = b.kSmallest(k, rootPtr, 7, 4);
	std::cout << std::to_string(k) <<"-smallest number in tree: " << std::to_string(smallest) << "\n";
	delete rootPtr;
}
