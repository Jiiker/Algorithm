#include <bits/stdc++.h>

using namespace std;
int N = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int result = INT_MAX;

void DFS(int cave[][125], int vis[][125], int x, int y, int sum)
{
  if (sum > result)
    return;
  
  if (x == N - 1 && y == N - 1)
  {
    if (sum < result)
      result = sum;
    return;
  }

  stack<pair<int, int>> S;

  S.push({x, y});
  vis[x][y] = 1;

  while(!S.empty())
  {
    pair<int, int> cur = S.top(); S.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx >= N || ny >= N || nx < 0 || ny < 0)
        continue;
      if (vis[nx][ny] == 1)
        continue;

      vis[nx][ny] = 1;
      DFS(cave, vis, nx, ny, sum + cave[nx][ny]);
      vis[nx][ny] = 0;
    }
  }

  return;
}

int main()
{
  int idx = 1;
  while(1)
  {
    result = INT_MAX;
    cin >> N;

    if (N != 0)
    {
      int cave[125][125] = { 0 };
      int vis[125][125] = { 0 };
      stack<pair<int, int>> S;

      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++)
        {
          cin >> cave[i][j];
        }
      }

      DFS(cave, vis, 0, 0, cave[0][0]);

      idx++;
    }
    else
      break;


    cout << "Problem " << idx << ": " << result << '\n';
  }

  return 0;
}