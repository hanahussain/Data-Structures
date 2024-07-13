#include "Node.h"
#include <stdlib.h>

//BST will be a collection of Nodes
//All the node class is is setters and getters and data (numbers) for each node; each node connects to its parent and left/right child, if any

Node::Node(){ //default everything to NULL, most will change at BST construction
	this->left = NULL;
	this->right = NULL;
	//this->parent = NULL;
	Node::number = -1;
}

Node* Node::getLeft(){
	return left;
}

void Node::setLeft(Node* left){
	this->left = left;
}

Node* Node::getRight(){
	return right;
}

void Node::setRight(Node* right){
	this->right = right;
}

int Node::getNumber(){
	return number;
}

void Node::setNumber(int number){
	Node::number = number;
}

Node::~Node(){
	//deletion will happen in main
}
