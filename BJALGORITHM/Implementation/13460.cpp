#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int result = 100;
void tilt_board(char board[][10], int cnt, int dir);

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  char input_board[10][10] = { '\0' };

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
      cin >> input_board[i][j];
  }

  for (int dir = 0; dir < 4; dir++)
  {
    tilt_board(input_board, 1, dir);
  }

  if (result == 100)
  {
    cout << -1;
    return 0;
  }

  cout << result;
  return 0;
}

void tilt_board(char board[][10], int cnt, int dir)
{
  if (cnt == 11 || cnt >= result)
  {
    return;
  }

  char copy_board[10][10] = { '\0' };
  copy(&board[0][0], &board[0][0] + 100, &copy_board[0][0]);
  int flag = 0;
  queue<pair<int, int> > Q;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (copy_board[i][j] == 'R' || copy_board[i][j] == 'B')
      {
        Q.push({i, j});
      }
    }
  }

  while(!Q.empty())
  {
    pair<int, int> cur = Q.front(); Q.pop();
    int nx = cur.first + dx[dir];
    int ny = cur.second + dy[dir];

    if (copy_board[nx][ny] == '#')
    {
      flag = 1;
    }
    else if (copy_board[nx][ny] == '.')
    {
      copy_board[nx][ny] = copy_board[cur.first][cur.second];
      copy_board[cur.first][cur.second] = '.';
      Q.push({nx, ny});
    }
    else if (copy_board[nx][ny] == 'R' || copy_board[nx][ny] == 'B')
    {
      if (flag == 0)
      {
        Q.push({cur.first, cur.second});
      }
    }
    else if (copy_board[nx][ny] == 'O')
    {
      if (copy_board[cur.first][cur.second] == 'R')
      {
        if (cnt < result)
        {
          int rev_nx = nx;
          int rev_ny = ny;
          while (copy_board[rev_nx][rev_ny] != '#')
          {
            rev_nx = rev_nx - dx[dir];
            rev_ny = rev_ny - dy[dir];
            if (copy_board[rev_nx][rev_ny] == 'B')
            {
              return;
            }
          }
          result = cnt;
        }
        return;
      }
      if (copy_board[cur.first][cur.second] == 'B')
      {
        return;
      }
    }
  }

  for (int next_dir = 0; next_dir < 4; next_dir++)
  {
    if (dir == next_dir)
      continue;
    tilt_board(copy_board, cnt + 1, next_dir);
  }

  return;
}