#include "BST.h"
#include "Node.h"
#include <stdlib.h>
#include <string>
#include <cstddef>
#include <iostream>
#include <sstream>

BST::BST(){
	int inputArr[15] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 82, 92, 95, 99};
	//this->inputArray = inputArr;
	for(int i = 0; i < 15; i++){
		this->inputArray[i] = inputArr[i];
	} //end for
} 

Node* BST::makeBST(int start, int end){
	if(start > end){ //we've reached either end when it starts crossing over
		return NULL;
	} //end if
	int middle = (start+end)/2;

	Node* root = new Node(); //will delete in main
	root->setNumber(inputArray[middle]);

	Node* left = makeBST(start, middle-1);
	root->setLeft(left);

	Node* right = makeBST(middle+1, end);
	root->setRight(right);

	return root;
} //end makeBST

//in this function I had to make the BST line-by-line using Node values and slash characters as branches
//The spacing just came from trial and error
//rootLR for example is the right child of the left subtree's root
void BST::printTree(Node* root){
	std::cout << "                           " << root->getNumber() << "\n";
	std::cout << "                        /      \\\n"; //24 then / then 6
	std::cout << "                    /             \\\n"; //20 then / then 13
	std::cout << "                 /                   \\\n"; //17 then / then 19

	std::cout << "           " << std::to_string((root->getLeft())->getNumber()) << "                           " << std::to_string((root->getRight())->getNumber()) << "\n";
        std::cout << "        /       \\                     /     \\\n"; //8 then / then 7 then \ then 20 then / then 5 
        
	Node* rootL = root->getLeft();
	std::string str1 = "    " + std::to_string(rootL->getLeft()->getNumber()) + "            " + std::to_string(rootL->getRight()->getNumber());
	Node* rootR = root->getRight();
	str1 += "               " + std::to_string(rootR->getLeft()->getNumber()) + "          " + std::to_string(rootR->getRight()->getNumber());
	std::cout << str1 << "\n";

	std::cout << "  /   \\        /      \\          /   \\       /    \\\n"; 
	Node* rootLL = rootL->getLeft();
	std::string str2 = std::to_string(rootLL->getLeft()->getNumber()) + "       " + std::to_string(rootLL->getRight()->getNumber()) + "   ";
	Node* rootLR = rootL->getRight();
	str2 += std::to_string(rootLR->getLeft()->getNumber()) + "        " + std::to_string(rootLR->getRight()->getNumber()) + "     ";
	Node* rootRL = rootR->getLeft();
	str2 += std::to_string(rootRL->getLeft()->getNumber()) + "      " + std::to_string(rootRL->getRight()->getNumber()) + "  ";
	Node* rootRR = rootR->getRight();
	str2 += std::to_string(rootRR->getLeft()->getNumber()) + "       " + std::to_string(rootRR->getRight()->getNumber()) + "\n";
	std::cout << str2;
} 

int BST::determineK(){
	bool validInput = false;
	bool checker = true;
	std::string nStr;
	int k;
	std::stringstream ss;
	while(!validInput){ //as long as their input is invalid in some way
		validInput = true;
		std::cout << "\nEnter an integer between 0 and 14: ";
		std::cin >> nStr; //save what they entered as a string
		for(int i = 0; i < nStr.length(); i++){ //check each character in nStr 
			if(isdigit(nStr[i]) == false){ //if any character is not a number, it's not a number
				validInput = false; //so we need to ask them again
				i = nStr.length(); //exit loop
				std::cout << "Invalid input. Please enter an integer. \n";																			} //end if
		} //end for
		if(validInput){ //check to see if it passed integer test
			ss << nStr;
			ss >> k; //store input into an integer	
			ss.clear();																								           ss.str("");
			if(k > 14 or k < 0){ //ensure their number is between 0 and 14, otherwise
				validInput = false; //run through while loop again
				std::cout << "Your integer should be between 0 and 14 \n"; //error message to user
			} //end if
		} //end outer if 	
	} //end while
	return k;
} //end determineK

//goal: return k-smallest value in the tree, so if user wants k=5, return 5th smallest number in tree
//uses the fact that input array is 15 to its advantage
//operation starts at 4 bc that's the difference between root and its children, position-wise
//operation gets divided by 2 because the farther down you go into tree, the lesser the positions differ by
int BST::kSmallest(int k, Node* root, int middle, int operation){
	int newVal;
	if(k == middle){
		newVal = root->getNumber(); //return
	} else if (k < middle){
		root = root->getLeft();
		middle = middle-operation; //update middle to position of root in array
		operation = operation/2;	
		newVal = kSmallest(k, root, middle, operation);
	} else {
		root = root->getRight();
		middle = middle+operation;
		operation = operation/2;
		newVal = kSmallest(k, root, middle, operation);
	} //end if else														    }
	return newVal;
} //end kSmallest


