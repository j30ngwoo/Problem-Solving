#include <iostream>

using namespace std;

void input_data(void);
void palindrome(void);
void print_result(void);
int is_palindrome(int index);
void print_square(void);

int size_of_sequence, number_of_questions;
pair<int, int> questions[1000000];
int sequences[2001];
int check_palindrome[2001][2001];
int result[1000000];

int main(void)
{
	ios::sync_with_stdio(false);
    
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

	fill(check_palindrome[0], check_palindrome[2000], -1);

	return;
}

void palindrome(void)
{
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

	else if (check_palindrome[front_index][back_index] == 0) // is not palindrome
		return (0);

	else // unknown
	{
		int i = -1;
		int half_of_diff = (back_index - front_index) / 2;
		while (++i <= half_of_diff)
		{
			if (sequences[front_index + i] != sequences[back_index - i])
			{
				check_palindrome[front_index][back_index] = 0; // when is not palindrome
				return (0);
			}
		}
		// when is palindrome
		i = -1;
		while (++i <= half_of_diff)
			check_palindrome[front_index + i][back_index - i] = 1;
		return (1);
	}

	return (-1);
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