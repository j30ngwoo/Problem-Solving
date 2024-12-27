#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct s_info
{
	int r_x;
	int r_y;
	int r_move_len;
	int	b_x;
	int	b_y;
	int b_move_len;
	int prev_direction;
	int	move_count;
}	t_info;

void	move_to_direction(int *x, int *y, int *move_len, int direction);
void	go(t_info next_info, int direction);

//void (*go_funcs[4])(t_info) = {go_left, go_right, go_up, go_down};
int	go_x[4] = {0, 1, 0, -1};
int go_y[4] = {-1, 0, 1, 0};
char board[10][10];
queue<t_info> q;
pair<int, int> coord_r, coord_b, coord_h;
int	n, m;

enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

void	prt_board(t_info next_info, int direction)
{
	cout << "direction: " << direction << '\n';
	cout << "R:" << next_info.r_x << ", " << next_info.r_y << ", " << next_info.r_move_len << '\n';
	cout << "B:" << next_info.b_x << ", " << next_info.b_y << ", " << next_info.b_move_len << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (next_info.r_x == j && next_info.r_y == i)
				cout << 'R';
			else if (next_info.b_x == j && next_info.b_y == i)
				cout << 'B';
			else
				cout << board[i][j];
		}
		cout << '\n';	
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char	tmp;
			cin >> tmp;
			if (tmp == 'R')
				coord_r = make_pair(j, i);
			else if (tmp == 'B')
				coord_b = make_pair(j, i);
			else if (tmp == 'O')
				coord_h = make_pair(j, i);
			if (tmp == '#')
				board[i][j] = '#';
			else if (tmp == 'O')
				board[i][j] = 'O';
			else
				board[i][j] = '.';
		}	
	}
	t_info init_info = {coord_r.first, coord_r.second, 0, coord_b.first, coord_b.second, 0, -1, 0};
	//prt_board(init_info, -1);
	q.push(init_info);
	while (!q.empty())
	{
		t_info	prev_info = q.front();
		if (prev_info.move_count == 10)
			break ;
		q.pop();
		for (int direction = 0; direction < 4; direction++)
			if (prev_info.prev_direction != direction && (prev_info.prev_direction + 2) % 4 != direction
				|| prev_info.prev_direction == -1)
				go(prev_info, direction);
	}
	cout << -1 << '\n';
	return (0);
}

void	go(t_info next_info, int direction)
{
	next_info.move_count++;
	next_info.prev_direction = direction;
	move_to_direction(&next_info.b_x, &next_info.b_y, &next_info.b_move_len, direction);
	move_to_direction(&next_info.r_x, &next_info.r_y, &next_info.r_move_len, direction);
	if (next_info.b_x == coord_h.first && next_info.b_y == coord_h.second)
		return ;
	else if (next_info.r_x == coord_h.first && next_info.r_y == coord_h.second)
	{
		cout << next_info.move_count << '\n';
		exit(0);
	}
	if (next_info.r_x == next_info.b_x && next_info.r_y == next_info.b_y)
	{
		if (next_info.r_move_len > next_info.b_move_len)
			next_info.r_x += go_x[(direction + 2) % 4], next_info.r_y += go_y[(direction + 2) % 4];
		else
			next_info.b_x += go_x[(direction + 2) % 4], next_info.b_y += go_y[(direction + 2) % 4];
	}
	//prt_board(next_info, direction);
	q.push(next_info);
}

void	move_to_direction(int *x, int *y, int *move_len, int direction)
{
	*move_len = 0;
	while (1)
	{
		int next_x = *x + go_x[direction];
		int next_y = *y + go_y[direction];

		if (board[next_y][next_x] == '.')
		{
			*x = next_x, *y = next_y;
			(*move_len)++;
		}
		else if (board[next_y][next_x] == '#')
			break ;
		else
		{
			*x = next_x, *y = next_y;
			(*move_len)++;
			break ;
		}
	}
}

