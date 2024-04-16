#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int n1, n2, T;
  string left_ant, right_ant;
  char line[100];
  int idx = 0;

  fill(line, line + 100, '\0');

  cin >> n1 >> n2 >> left_ant >> right_ant >> T;
  reverse(left_ant.begin(), left_ant.end());

  while (idx < n1)
  {
    line[(idx + T) * 2] = left_ant[idx];
    idx++;
  }

  for (int i = 0; i < n2; i++)
  {
    line[(idx * 2) - 1] = right_ant[i];
    idx++;
  }

  for (int i = 0; i < 100; i++)
  {
    if (line[i])
      cout << line[i];
  }

  return 0;
}