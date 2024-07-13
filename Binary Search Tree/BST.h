#include "Node.h"

#ifndef BST_H_EXISTS
#define BST_H_EXISTS

class BST{
	private:
		int inputArray[15];

	public:
		BST();
		//Node makeBST(int start, int end, Node root);
		Node* makeBST(int start, int end);
		void printTree(Node* root);
		int determineK();
		int kSmallest(int k, Node* root, int middle, int operation);
};

#endif
