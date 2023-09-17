#include <bits/stdc++.h>

using namespace std;

int main()
{
  int arr[101][101] = { 0 };
  int cnt_max = 0;
  int N = 0;
  queue<pair<int, int> > Q;
  
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
    }
  }
  
  for (int k = 0; k <= 100; k++)
  {
    int vis[101][101] = { 0 };
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (arr[i][j] > k && vis[i][j] != 1)
        {
          cnt++;
          Q.push({i, j});
          vis[i][j] = 1;

          while(!Q.empty())
          {
            pair<int, int> cur = Q.front(); Q.pop();
            int dx[4] = { 1, 0, -1, 0 };
            int dy[4] = { 0, 1, 0, -1 };

            for (int dir = 0; dir < 4; dir++)
            {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];

              if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
              if (arr[nx][ny] <= k || vis[nx][ny] == 1)
                continue;
              
              Q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
      }
    }
    if (cnt > cnt_max)
      cnt_max = cnt;
  }
  cout << cnt_max;

  return 0;
}