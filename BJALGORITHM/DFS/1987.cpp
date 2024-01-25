#include <bits/stdc++.h>

using namespace std;
int R = 0, C = 0;
char board[20][20] = { 0 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int max_cnt = 0;

void dfs(int arr[26], int x, int y, int cnt)
{
  for (int dir = 0; dir < 4; dir++)
  {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= R || ny >= C)
      continue;
    if (arr[board[nx][ny] - 'A'] == 1)
      continue;
    
    arr[board[nx][ny] - 'A'] = 1;
    dfs(arr, nx, ny, cnt + 1);
    arr[board[nx][ny] - 'A'] = 0;
    
  }

  if (cnt > max_cnt)
    max_cnt = cnt;
  
  return;
}

int main()
{
  int check_alp[26] = { 0 };
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
      cin >> board[i][j];
  }

  check_alp[board[0][0] - 'A'] = 1;
  dfs(check_alp, 0, 0, 1);

  cout << max_cnt;

  return 0;
}