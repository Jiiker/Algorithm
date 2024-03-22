#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
  int N = 0;
  char board[50][50];
  vector<char> path;
  int start_x = 0, start_y = 0, cur_x = 0, cur_y = 0, min_x = 0, min_y = 0, max_x = 0, max_y = 0;
  int x_len = 0, y_len = 0;
  int dir = 0;

  for (int i = 0; i < 50; i++)
  {
    for (int j = 0; j < 50; j++)
      board[i][j] = '#';
  }
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    char c;

    cin >> c;
    path.push_back(c);
    if (c == 'R')
    {
      if (dir == 3)
        dir = 0;
      else
        dir++;
      continue;
    }
    else if (c == 'L')
    {
      if (dir == 0)
        dir = 3;
      else
        dir--;
      continue;
    }

    cur_x = cur_x + dx[dir];
    cur_y = cur_y + dy[dir];

    if (cur_x < min_x)
      min_x = cur_x;
    if (cur_y < min_y)
      min_y = cur_y;
    if (cur_x > max_x)
      max_x = cur_x;
    if (cur_y > max_y)
      max_y = cur_y;
  }

  x_len = max_x - min_x + 1;
  y_len = max_y - min_y + 1;
  start_x = min_x * (-1);
  start_y = min_y * (-1);

  board[start_x][start_y] = '.';
  dir = 0;
  cur_x = start_x;
  cur_y = start_y;

  for (int i = 0; i < N; i++)
  {
    if (path[i] == 'R')
    {
      if (dir == 3)
        dir = 0;
      else
        dir++;
      continue;
    }
    else if (path[i] == 'L')
    {
      if (dir == 0)
        dir = 3;
      else
        dir--;
      continue;
    }

    cur_x = cur_x + dx[dir];
    cur_y = cur_y + dy[dir];
    board[cur_x][cur_y] = '.';
  }

  for (int i = 0; i < x_len; i++)
  {
    for (int j = 0; j < y_len; j++)
    {
      cout << board[i][j];
    }
    cout << '\n';
  }

  return 0;
}