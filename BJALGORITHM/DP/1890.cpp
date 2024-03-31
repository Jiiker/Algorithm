#include <bits/stdc++.h>

using namespace std;

int main()
{
  int board[100][100] = { 0 };
  long long cnt[100][100] = { 0 };
  int dx[2] = { 1, 0 };
  int dy[2] = { 0, 1 };
  int N = 0;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> board[i][j];
    }
  }

  cnt[0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (cnt[i][j] == 0)
        continue;
      if (board[i][j] == 0)
        continue;
      
      for (int dir = 0; dir < 2; dir++)
      {
        int nx = i + (board[i][j] * dx[dir]);
        int ny = j + (board[i][j] * dy[dir]);

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
          continue;
        
        cnt[nx][ny] = cnt[nx][ny] + cnt[i][j];
      }
    }
  }

  cout << cnt[N-1][N-1];

  return 0;
}