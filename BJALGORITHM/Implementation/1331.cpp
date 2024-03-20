#include <bits/stdc++.h>

using namespace std;

int main()
{
  int board[6][6] = { 0 };
  int prev_x, prev_y;
  int st_x, st_y;
  string result = "Valid";

  for (int i = 0; i < 36; i++)
  {
    char x, y;
    int x_num, y_num;

    cin >> x >> y;
    x_num = x - 'A';
    y_num = y - '1';
    
    if (board[x_num][y_num] == 1)
    {
      result = "Invalid";
    }
    board[x_num][y_num] = 1;

    if (i == 0)
    {
      st_x = x_num;
      st_y = y_num;
      prev_x = x_num;
      prev_y = y_num;
      continue;
    }

    if (!((abs(prev_x - x_num) == 2 && abs(prev_y - y_num) == 1) || (abs(prev_x - x_num) == 1 && abs(prev_y - y_num) == 2)))
    {
      result = "Invalid";
    }

    prev_x = x_num;
    prev_y = y_num;
  }

  if (!((abs(prev_x - st_x) == 2 && abs(prev_y - st_y) == 1) || (abs(prev_x - st_x) == 1 && abs(prev_y - st_y) == 2)))
  {
    result = "Invalid";
  }

  cout << result;

  return 0;
}