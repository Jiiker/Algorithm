#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  int map[1001][1001] = { 0 };
  int vis[1001][1001] = { 0 };
  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  queue<pair<int, int>> Q;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 2)
      {
        Q.push({i, j});
        map[i][j] = 0;
        vis[i][j] = 1;
      }
    }
  }

  while(!Q.empty())
  {
    pair<int, int> cur = Q.front(); Q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx >= n || ny >= m || nx < 0 || ny < 0)
        continue;
      if (map[nx][ny] == 0 || vis[nx][ny] != 0)
        continue;
      
      vis[nx][ny] = 1;
      map[nx][ny] = map[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] == 0 && map[i][j] == 1)
        map[i][j] = -1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}