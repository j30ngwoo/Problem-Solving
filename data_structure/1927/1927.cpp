#include <iostream>
using namespace std;

void push(int now_value);
void pop(void);
void heapify(int i);
void swap(int &a, int &b);

int heap[100001], count = 1;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (--n >= 0)
	{
		int input;
		cin >> input;
		if (input == 0)
			pop();
		else
			push(input);
	}

	return (0);
}

void push(int i)
{
	heap[count] = i;
	int parent = count / 2, child = count;
	while (child > 1 && heap[parent] < heap[child])
	{
		swap(heap[parent], heap[child]);
		child = parent;
		parent /= 2;
	}

	count++;

	return ;
}

void pop(void)
{
	if (count > 1)
	{	
		cout << heap[1] << '\n';
		heap[1] = heap[count - 1];
		count--;
		heapify(1);
	}
	else
		cout << 0 << '\n';

	return ;
}

void heapify(int i)
{
	int maximim = i, left = i * 2, right = i * 2 + 1;
	if (heap[maximim] < heap[left] && left < count)
		maximim = left;
	if (heap[maximim] < heap[right] && right < count)
		maximim = right;

	if (maximim != i)
	{
		swap(heap[i], heap[maximim]);
		heapify(maximim);
	}

	return ;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

	return ;
}