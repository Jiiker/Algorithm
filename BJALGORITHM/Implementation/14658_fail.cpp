#include <bits/stdc++.h>

using namespace std;
int shootingstar[500001][500001] = { 0 };
int N, M, L, K;
int max_star = 0;

int main()
{
  cin >> N >> M >> L >> K;

  for (int i = 0; i < K; i++)
  {
    int x, y;
    cin >> x >> y;

    shootingstar[x][y] = 1;
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      shootingstar[i][j] = max(max(shootingstar[i-1][j], shootingstar[i][j-1]), shootingstar[i-1][j-1]) + shootingstar[i][j];
    }
  }

  for (int i = L; i <= N; i++)
  {
    for (int j = L; j <= M; j++)
    {
      if (shootingstar[i][j] - shootingstar[i-L+1][j-L+1] + 1 > max_star)
        max_star = shootingstar[i][j] - shootingstar[i-L+1][j-L+1] + 1;
    }
  }

  cout << max_star;

  return 0;
}