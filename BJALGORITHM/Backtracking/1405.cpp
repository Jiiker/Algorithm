#include <bits/stdc++.h>

using namespace std;

int vis[30][30] = { 0 };
int N = 0;
double east, west, south, north;
double sum = 0.0, percentage = 1.0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void backtracking(int k, int col, int row);

int main()
{  
  cin >> N >> east >> west >> south >> north;

  vis[15][15] = 1;
  backtracking(0, 15, 15);

  cout.precision(9);
  cout << sum;

  return 0;
}

void backtracking(int k, int col, int row)
{
  if (k == N)
  {
    sum = sum + percentage;
    return;
  }
  for (int dir = 0; dir < 4; dir++)
  {
    int nx = col + dx[dir];
    int ny = row + dy[dir];
    
    if (vis[nx][ny] == 1)
      continue;
    if (east == 0 && dir == 0)
      continue;
    if (west == 0 && dir == 1)
      continue;
    if (south == 0 && dir == 2)
      continue;
    if (north == 0 && dir == 3)
      continue;
    
    vis[nx][ny] = 1;
    if (dir == 0)
    {
      percentage = percentage * east / 100;
      backtracking(k + 1, nx, ny);
      percentage = percentage /(east / 100);

    }
    else if (dir == 1)
    {
      percentage = percentage * west / 100;
      backtracking(k + 1, nx, ny);
      percentage = percentage /(west / 100);
    }
    else if (dir == 2)
    {
      percentage = percentage * south / 100;
      backtracking(k + 1, nx, ny);
      percentage = percentage /(south / 100);
    }
    else
    {
      percentage = percentage * north / 100;
      backtracking(k + 1, nx, ny);
      percentage = percentage /(north / 100);
    }
    vis[nx][ny] = 0;
  }
  return;
}