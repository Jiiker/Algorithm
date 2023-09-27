#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  int maze[1001][1001] = { 0 };
  int dx[3] = { 1, 0, 1 };
  int dy[3] = { 0, 1, 1 };

  cin >> N >> M;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
      cin >> maze[i][j];
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      if (i != 0 && j != 0)
        maze[i][j] += max(maze[i - 1][j], maze[i][j - 1]);
    }
  }

  cout << maze[N][M];

  return 0;
}
