#include <bits/stdc++.h>

using namespace std;
int R, C;
char yard[250][250];
int left_wolves, left_sheeps;

void BFS()
{
  int vis[250][250] = { 0 };
  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      int flag = 0;
      int wolves = 0, sheeps = 0;
      queue<pair<int, int>> Q;

      if(yard[i][j] == '#' || vis[i][j] == 1)
        continue;

      Q.push({i, j});
      vis[i][j] = 1;
      if (yard[i][j] == 'v')
        wolves++;
      else if (yard[i][j] == 'o')
        sheeps++;

      while (!Q.empty())
      {
        pair<int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (yard[nx][ny] == '#')
            continue;
          if (nx < 0 || ny < 0 || nx >= R || ny >= C)
          {
            flag = 1;
            continue;
          }
          if (vis[nx][ny] == 1)
            continue;
          
          vis[nx][ny] = 1;
          Q.push({nx, ny});

          if (yard[nx][ny] == 'v')
            wolves++;
          else if (yard[nx][ny] == 'o')
            sheeps++;
        }
      }

      if (flag)
        continue;

      if (wolves >= sheeps)
        left_wolves = left_wolves + wolves;
      else
        left_sheeps = left_sheeps + sheeps;
    }
  }
}

int main()
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> yard[i][j];
    }
  }

  BFS();

  cout << left_sheeps << ' ' << left_wolves;

  return 0;
}