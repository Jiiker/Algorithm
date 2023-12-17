#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
  int N = 0;
  int arr[3000] = { 0 };
  int DP[3000] = { 0 };
  int max_value = 0;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int prev_max = 0;
    cin >> arr[i];

    DP[i] = 1;

    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] < arr[i])
      {
        if (DP[j] > prev_max)
        {
          prev_max = DP[j];
          DP[i] = prev_max + 1;
        }
      }
    }

    if (DP[i] > max_value)
      max_value = DP[i];
  }
  cout << max_value;
  
  return 0;
}