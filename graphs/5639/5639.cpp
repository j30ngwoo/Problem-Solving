#include <iostream>

using namespace std;

struct Node {
	int Value;
	Node* Left;
	Node* Right;
};

class BinaryTree {
	private:
		Node* mRoot = nullptr;
	public:
		Node* getRoot(void);
		void Append(int newValue);
		void PostorderTraversal(Node* node);
};

Node* BinaryTree::getRoot(void) {
	return this->mRoot;
}

void BinaryTree::Append(int newValue) {
	if (mRoot == nullptr) {
		this->mRoot = new Node({newValue, nullptr, nullptr});
		return ;
	}
	Node *parent = mRoot;
	while (true) {
		if (newValue < parent->Value) {
			if (parent->Left == nullptr) {
				parent->Left = new Node({newValue, nullptr, nullptr});
				break ;
			}
			else {
				parent = parent->Left;
			}
		} else {
			if (parent->Right == nullptr) {
				parent->Right = new Node({newValue, nullptr, nullptr});
				break ;
			}
			else {
				parent = parent->Right;
			}
		}
	}
}

void BinaryTree::PostorderTraversal(Node* node) {
	if (node == nullptr)
		return ;
	PostorderTraversal(node->Left);
	PostorderTraversal(node->Right);
	cout << node->Value << '\n';
}

int main(void) {
	int n;
	BinaryTree tree;

	while (cin >> n)
		tree.Append(n);
	tree.PostorderTraversal(tree.getRoot());
	
	return (0);
}