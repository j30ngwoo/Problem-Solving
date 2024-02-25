#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
};

int compareAbs(int a, int b) {
	if (abs(a) == abs(b))
		return (a - b);
	else
		return (abs(a) - abs(b));
}

int popMinimum(node** nowNode) {
	if (*nowNode == nullptr)
		return (0);
	if ((*nowNode)->left == nullptr) {
		int value = (*nowNode)->value;
		free(*nowNode);
		*nowNode = (*nowNode)->right; 
		return (value);
	}
	return (popMinimum(&((*nowNode)->left)));
}

node* makeNode(int value) {
	node* newNode = new node;
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return (newNode);
}

void appendNode(node** parentPtr, int nowValue) {
	if (*parentPtr == nullptr) {
		*parentPtr = makeNode(nowValue);
		return ;
	}
	if (compareAbs((*parentPtr)->value, nowValue) > 0)
		appendNode(&((*parentPtr)->left), nowValue);
	else
		appendNode(&((*parentPtr)->right), nowValue);
}

int n, x;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	node* root = nullptr;
	cin >> n;
	FOR(i, n) {
		cin >> x;
		if (x == 0)
			cout << popMinimum(&root) << '\n';
		else
			appendNode(&root, x);
	}
	return (0);
}