#include <bits/stdc++.h>

using namespace std;
int N = 0, M = 0;
char board[50][50];
int min_cnt = INT_MAX;

int check_board(int x, int y, char first_word)
{
  int check[50][50] = { 0 };
  int cnt = 0;
  char second_word;
  queue<pair<int, int>> Q;
  
  if (first_word == 'W')
    second_word = 'B';
  else
    second_word = 'W';

  Q.push({x, y});
  check[x][y] = 1;
  if (board[x][y] != first_word)
    cnt++;

  while (!Q.empty())
  {
    pair<int, int> cur = Q.front(); Q.pop();
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < x || ny < y || nx >= x + 8 || ny >= y + 8)
        continue;
      if (check[nx][ny] != 0)
        continue;

      Q.push({nx, ny});
      check[nx][ny] = check[cur.first][cur.second] + 1;

      if (check[nx][ny] % 2 == 1 && board[nx][ny] != first_word)
        cnt++;
      else if (check[nx][ny] % 2 == 0 && board[nx][ny] != second_word)
        cnt++;
    }
  }

  return cnt;
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      char c;
      cin >> c;
      board[i][j] = c;
    }
  }

  for (int i = 0; i <= N - 8; i++)
  {
    for (int j = 0; j <= M - 8; j++)
    {
      int cnt = min(check_board(i, j, 'W'), check_board(i, j, 'B'));

      if (cnt < min_cnt)
        min_cnt = cnt;
    }
  }

  cout << min_cnt;

  return 0;
}