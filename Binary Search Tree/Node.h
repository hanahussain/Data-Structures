#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class Node{
	private:
		Node* left;
		Node* right;
		Node* parent;
		int number;

	public:
		Node();
		~Node();
		Node* getLeft();
		void setLeft(Node* left);
		Node* getRight();
		void setRight(Node* right);
		int getNumber();
		void setNumber(int number);
};

#endif
