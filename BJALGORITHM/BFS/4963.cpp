#include <bits/stdc++.h>

using namespace std;

int main()
{
  while(1)
  {
    int width, height;
    int cnt = 0;
    int arr[51][51] = { 0 };
    int vis[51][51] = { 0 };
    queue<pair<int, int> > Q;
    cin >> width >> height;

    if (width == 0 && height == 0)
      return 0;

    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
        cin >> arr[i][j];
    }

    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        if (arr[i][j] == 1 && vis[i][j] == 0)
        {
          cnt++;
          vis[i][j] = 1;
          Q.push({i, j});
          
          while (!Q.empty())
          {
            pair<int, int> cur = Q.front(); Q.pop();
            int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
            int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

            for (int dir = 0; dir < 8; dir++)
            {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];

              if (nx >= height || ny >= width || nx < 0 || ny < 0)
                continue;
              if (vis[nx][ny] == 1 || arr[nx][ny] == 0)
                continue;
              
              Q.push({nx, ny});
              vis[nx][ny] = 1;
            }
          }
        }
      }
    }
    cout << cnt << '\n';
    cnt = 0;
  }

  return 0;
}