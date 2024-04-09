#include <bits/stdc++.h>

using namespace std;
int board[5][5] = { 0 };
set<string> S;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void find_num(pair<int, int> start, string s)
{
  if (s.length() == 6)
  {
    S.insert(s);
    return;
  }

  for (int dir = 0; dir < 4; dir++)
  {
    int nx = start.first + dx[dir];
    int ny = start.second + dy[dir];

    if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
      continue;
    
    find_num({nx, ny}, s + to_string(board[nx][ny]));
  }
  return;
}

int main()
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      string str;
      find_num({i, j}, str);
    }
  }

  cout << S.size();

  return 0;
}