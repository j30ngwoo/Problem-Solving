#include <iostream>

using namespace std;

class Node {
	private:
		int value;
		Node* left;
		Node* right;

	public:
		Node(int value) {
			this->value = value;
			this->left = nullptr;
			this->right = nullptr;
		}

		int getValue() {return this->value;}
		Node* getLeft() {return this->left;}
		Node* getRight() {return this->right;}

		void setValue(int value) {this->value = value;}
		void setLeft(Node* left) {this->left = left;}
		void setRight(Node* right) {this->right = right;}
};

class BinaryTree {
	private:
		Node* root = nullptr;

	public:
		Node* getRoot() {return (root);}

		void insertNode(Node* node, Node** parent) {
			if (parent == nullptr) {
				*parent = node;
			} else if (node->getValue() < (*parent)->getValue()) {
				insertNode(node, &((*parent)->getLeft()));
			} else if (node->getValue() > (*parent)->getValue()) {
				insertNode(node, &((*parent)->getRight()));
			} else {
				exit(1);
			}
		}
};

int main(void) {
	string value;
	BinaryTree binaryTree;

	while (getline(cin, value)) {
		binaryTree.insertNode(new Node(stoi(value)), binaryTree.getRoot());
	}

	return (0);
}
