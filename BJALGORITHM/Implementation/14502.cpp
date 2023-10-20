#include <bits/stdc++.h>

using namespace std;
int lab_map[8][8] = { 0 };
int N = 0, M = 0;
int BFS();

int main()
{
  int max_saferegion = 0;
  vector<pair<int, int>> cordinate;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> lab_map[i][j];
      if(lab_map[i][j] == 0)
        cordinate.push_back({i, j});
    }
  }

  for (int i = 0; i < cordinate.size() - 2; i++)
  {
    for (int j = i + 1; j < cordinate.size() - 1; j++)
    {
      for (int k = j + 1; k < cordinate.size(); k++)
      {
        int saferegion = 0;
        pair<int, int> wall1 = cordinate[i];
        pair<int, int> wall2 = cordinate[j];
        pair<int, int> wall3 = cordinate[k];

        lab_map[wall1.first][wall1.second] = 1;
        lab_map[wall2.first][wall2.second] = 1;
        lab_map[wall3.first][wall3.second] = 1;
        
        if (BFS() > max_saferegion)
          max_saferegion = BFS();

        lab_map[wall1.first][wall1.second] = 0;
        lab_map[wall2.first][wall2.second] = 0;
        lab_map[wall3.first][wall3.second] = 0;
      }
    }
  }

  cout << max_saferegion;

  return 0;
}

int BFS()
{
  int result = 0;
  int copy_arr[8][8] = { 0 };
  int vis_virus[8][8] = { 0 };
  int vis_safe[8][8] = { 0 };
  queue<pair<int, int> > Q_safe;
  queue<pair<int, int> > Q_virus;

  copy(&lab_map[0][0], &lab_map[0][0] + 64, &copy_arr[0][0]);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (copy_arr[i][j] == 2 && vis_virus[i][j] == 0)
      {
        Q_virus.push({i, j});
        vis_virus[i][j] = 1;

        while (!Q_virus.empty())
        {
          pair<int, int> cur = Q_virus.front(); Q_virus.pop();
          int dx[4] = {1, 0, -1, 0};
          int dy[4] = {0, 1, 0, -1};

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx >= N || nx < 0 || ny >= M || ny < 0)
              continue;
            if (copy_arr[nx][ny] == 1 || copy_arr[nx][ny] == 2 || vis_virus[nx][ny] == 1)
              continue;
            
            Q_virus.push({nx,ny});
            vis_virus[nx][ny] = 1;
            copy_arr[nx][ny] = 2;
          }
        }
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (copy_arr[i][j] == 0 && vis_safe[i][j] == 0)
      {
        Q_safe.push({i, j});
        vis_safe[i][j] = 1;
        result++;

        while (!Q_safe.empty())
        {
          pair<int, int> cur = Q_safe.front(); Q_safe.pop();
          int dx[4] = {1, 0, -1, 0};
          int dy[4] = {0, 1, 0, -1};

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx >= N || nx < 0 || ny >= M || ny < 0)
              continue;
            if (copy_arr[nx][ny] == 1 || copy_arr[nx][ny] == 2 || vis_safe[nx][ny] == 1)
              continue;
            
            Q_safe.push({nx, ny});
            vis_safe[nx][ny] = 1;
            result++;
          }
        }
      }
    }
  }

  return result;
}