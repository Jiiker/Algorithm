#include <bits/stdc++.h>

using namespace std;
int path[10][10] = { 0 };
int N, M;
int min_value = INT_MAX;

void toTheMoon(int sum, int x, int y, int k, int dir)
{
  if (k == N)
  {
    if (min_value > sum)
      min_value = sum;

    return;
  }

  for (int i = -1; i <= 1; i++)
  {
      int nx = x + 1;
      int ny = y + i;

      if (nx >= N || ny < 0 || ny >= M)
        continue;
      if (dir == i)
        continue;
      
      toTheMoon(sum + path[nx][ny], nx, ny, k + 1, i);
  }

  return;
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> path[i][j];
    }
  }

  for (int i = 0; i < M; i++)
  {
    toTheMoon(path[0][i], 0, i, 1, 9);
  }

  cout << min_value;

  return 0;
}