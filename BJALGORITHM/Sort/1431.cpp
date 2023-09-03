#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  string serial[55];
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> serial[i];

  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < N - 1 - i; j++)
    {
      if (serial[j].length() < serial[j+1].length())
        continue;
      if (serial[j].length() > serial[j+1].length()) 
      {
        swap(serial[j], serial[j+1]);
        continue;
      }
      int sum_A = 0, sum_B = 0;
      for (int k = 0; k < serial[j].length(); k++)
      {
        if (serial[j][k] > '0' && serial[j][k] <= '9')
          sum_A = sum_A + (serial[j][k] - '0');
      }
      for (int k = 0; k < serial[j+1].length(); k++)
      {
        if (serial[j+1][k] > '0' && serial[j+1][k] <= '9')
          sum_B = sum_B + (serial[j+1][k] - '0');
      }
      if (sum_A < sum_B)
        continue;
      if (sum_A > sum_B)
      {
        swap(serial[j], serial[j+1]);
        continue;
      }
      if (serial[j] > serial[j+1])
        swap(serial[j], serial[j+1]);
    }
  }

  for (int i = 0; i < N; i++)
    cout << serial[i] << '\n';

  return 0;
}