#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int board[][105], int N, int M)
{
  int vis[105][105] = { 0 };
  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  vector<int> result;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (board[i][j] == 1 || vis[i][j] == 1)
        continue;
      
      queue<pair<int, int>> Q;
      int cnt = 0;

      Q.push({i, j});
      vis[i][j] = 1;
      cnt++;

      while (!Q.empty())
      {
        pair<int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
          if (board[nx][ny] == 1 || vis[nx][ny] == 1)
            continue;
          
          Q.push({nx, ny});
          vis[nx][ny] = 1;
          cnt++;
        }
      }

      result.push_back(cnt);
    }
  }

  return result;
}

int main() 
{
  int board[105][105] = { 0 };
  int N, M, K;
  vector<int> result;

  cin >> M >> N >> K;

  for (int k = 0; k < K; k++)
  {
    int st_x, st_y;
    int end_x, end_y;

    cin >> st_x >> st_y >> end_x >> end_y;

    for (int i = st_x; i < end_x; i++)
    {
      for (int j = st_y; j < end_y; j++)
      {
        board[i][j] = 1;
      }
    }
  }

  result = bfs(board, N, M);

  sort(result.begin(), result.end());

  cout << result.size() << '\n';
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ' ';
  }

  return 0;
}