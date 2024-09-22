#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
  int dy[8] = {1, 0, -1, 1, 1, 0, -1, -1};
  int farm[100][70] = { 0 };
  int vis[100][70] = { 0 };
  int result = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> farm[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (vis[i][j])
        continue;
      
      queue<pair<int, int>> Q;
      int isTop = 1;

      Q.push({i, j});

      while(!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        vis[cur.first][cur.second] = 1;

        for (int dir = 0; dir < 8; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
          if (farm[nx][ny] > farm[cur.first][cur.second])
            isTop = 0;
          if (vis[nx][ny])
            continue;
          if (farm[nx][ny] != farm[cur.first][cur.second])
            continue;
          
          Q.push({nx, ny});
        }
      }

      if (isTop)
        result++;
    }
  }

  cout << result;

  return 0;
}