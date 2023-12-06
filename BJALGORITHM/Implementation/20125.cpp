#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int N = 0;
  char arr[1000][1000];
  pair<int, int> head;
  int nx, ny;
  queue<pair<int, int>> Q;
  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  cin >> N;

  int left_arm = 0, right_arm = 0, waist = 0, left_leg = 0, right_leg = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
      if (arr[i-1][j] == '*' && arr[i][j-1] == '*' && arr[i][j] == '*')
        head = {i, j};
    }
  }

  nx = head.first;
  ny = head.second;
  while (arr[nx][ny] == '*')
  {
    nx += dx[3];
    ny += dy[3];
    if (arr[nx][ny] == '_')
      break;
    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      break;
    left_arm++;
  }

  nx = head.first;
  ny = head.second;
  while (arr[nx][ny] == '*')
  {
    nx += dx[1];
    ny += dy[1];
    if (arr[nx][ny] == '_')
      break;
    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      break;
    right_arm++;
  }

  nx = head.first;
  ny = head.second;
  while (arr[nx][ny] == '*')
  {
    nx += dx[0];
    ny += dy[0];
    if (arr[nx][ny] == '_')
      break;
    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      break;
    waist++;
  }

  nx = head.first + waist + 1;
  ny = head.second - 1;
  while (arr[nx][ny] == '*')
  {
    left_leg++;
    nx += dx[0];
    ny += dy[0];
    if (arr[nx][ny] == '_')
      break;
    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      break;
  }


  nx = head.first + waist + 1;
  ny = head.second + 1;
  while (arr[nx][ny] == '*')
  {
    right_leg++;
    nx += dx[0];
    ny += dy[0];
    if (arr[nx][ny] == '_')
      break;
    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      break;
  }
  

  cout << head.first + 1 << ' ' << head.second + 1 << '\n' << left_arm << ' ' << right_arm << ' ' << waist << ' ' << left_leg << ' ' << right_leg;

  return 0;
}