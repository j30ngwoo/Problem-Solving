#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, size;
int n = 10;

void make_set(int n){
	parent.resize(n);
	for(int i=0; i<n; i++)
		parent[i] = i;
}

/*
int find(int i){
	if(parent[i] == i) 
		return (i);
	return (find(parent[i]));
}*/

int find(int i)
{
    if(parent[i] == i) 
		return i;
	parent[i] = find(parent[i]);
    return (parent[i]);
}

void unio(int a,int b)
{
    a = find(a);
    b = find(b);
	
	if (a == b)
		return ;

	if (size[a] < size[b])
		swap(a, b);
	
	parent[b] = a
	size[a] += size[b];
}

int main(void)
{
	for(int i=0; i<n; i++)
		parent[i] = 1;
	
	union1(0, 1);
	union1(1, 2);
	union1(2, 3);
	find(4) == n
}
