#include <bits/stdc++.h>

using namespace std;

int main()
{
  int arr[10005];
  int N = 0, M = 0;
  int left = 0, right = 0, result = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  while (left < N)
  {
    int sum = 0;
    for (int i = left; i < right; i++)
      sum = sum + arr[i];
    
    if (sum == M)
      result++;

    if (sum > M || right >= N)
    {
      left++;
      continue;
    }
    
    right++;
  }

  cout << result;

  return 0;
}