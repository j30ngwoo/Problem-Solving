#include <iostream>

using namespace std;

void input_data(void);
void palindrome(void);
void print_result(void);
int is_palindrome(int index);
void print_square(void);
void check_all_index(void);

int size_of_sequence, number_of_questions;
pair<int, int> questions[1000000];
int sequences[2001];
int check_palindrome[2001][2001];
int result[1000000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input_data();
	palindrome();
	print_result();

	return (0);
}

void input_data(void)
{
	cin >> size_of_sequence;

	int i = 0;
	while (++i <= size_of_sequence)
		cin >> sequences[i];

	cin >> number_of_questions;

	i = -1;
	while (++i < number_of_questions)
	{
		int a, b;
		cin >> a >> b;
		questions[i] = make_pair(a, b);
	}

	fill(check_palindrome[0], check_palindrome[2000], 0);

	return;
}

void palindrome(void)
{
	check_all_index();

	int i = -1;
	while (++i < number_of_questions)
		result[i] = is_palindrome(i);

	return;
}

int is_palindrome(int index)
{
	// print_square();

	int front_index = questions[index].first;
	int back_index = questions[index].second;

	if (check_palindrome[front_index][back_index] == 1) // is palindrome
		return (1);
	else // is not palindrome
		return (0);
}

void print_result(void)
{
	int i = -1;

	while (++i < number_of_questions)
		cout << result[i] << '\n';

	return;
}

void print_square(void)
{
	int i = 0;
	while (++i <= size_of_sequence)
	{
		int j = 0;
		while (++j <= size_of_sequence)
			cout << check_palindrome[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';

	return;
}

void check_all_index(void)
{
	int now_index = 0;

	while (++now_index <= size_of_sequence)
	{
		check_palindrome[now_index][now_index] = 1;

		int down_index = now_index;
		int up_index = now_index;
		while (--down_index >= 1 && ++up_index <= size_of_sequence 
			&& sequences[down_index] == sequences[up_index])
				check_palindrome[down_index][up_index] = 1;
		
		down_index = now_index + 1;
		up_index = now_index;
		while (--down_index >= 1 && ++up_index <= size_of_sequence
			&& sequences[down_index] == sequences[up_index])
				check_palindrome[down_index][up_index] = 1;
	}

	return ;
}