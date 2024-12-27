#include <iostream>
#include <map>
using namespace std;

struct Node {
	char left;
	char right;
};
int n;
map<char, Node> graph;

void preorder(char node) {
	if (node == '.')
		return ;
	cout << node;
	preorder(graph[node].left);
	preorder(graph[node].right);
}

void inorder(char node) {
	if (node == '.')
		return ;
	inorder(graph[node].left);
	cout << node;
	inorder(graph[node].right);
}

void postorder(char node) {
	if (node == '.')
		return ;
	postorder(graph[node].left);
	postorder(graph[node].right);
	cout << node;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		graph.insert({node, {left, right}});
	}
	
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
	return (0);
}