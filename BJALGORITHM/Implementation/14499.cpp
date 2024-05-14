#include <bits/stdc++.h>

using namespace std;

int dice[6][5] = {
  {1, 3, 4, 2, 5},
  {2, 3, 4, 6, 1},
  {3, 6, 1, 2, 5},
  {4, 1, 6, 2, 5},
  {5, 3, 4, 1, 6},
  {6, 3, 4, 5, 2}
};

int main()
{
  int N, M, x, y, K;
  int jido[20][20];
  int bottom_value = 6, cur_idx = 6, top_value = 1;

  cin >> N >> M >> x >> y >> K;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> jido[N][M];
    }
  }

  for (int i = 0; i < K; i++)
  {
    int cmd;
    cin >> cmd;

    if (cmd == 1)
      y++;
    else if (cmd == 2)
      y--;
    else if (cmd == 3)
      x--;
    else
      x++;
    
    cur_idx = dice[cur_idx-1][cmd];
    bottom_value = dice[cur_idx-1][0];
    top_value = dice[dice[cur_idx-1][2]-1][0];

    if (jido[x][y] == 0)
    {
      jido[x][y] = bottom_value;
    }
    else
    {
      dice[cur_idx-1][0] = jido[x][y];
      jido[x][y] = 0;
    }
    
    cout << top_value << '\n';
  }

  return 0;
}