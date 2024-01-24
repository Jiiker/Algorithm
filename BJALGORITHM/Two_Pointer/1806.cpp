#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, S;
  int arr[100000] = { 0 };
  int left = 0, right = 0;
  int sum = 0;
  int min_len = INT_MAX;
  int len = 0;
  int flag = 0;

  cin >> N >> S;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  while (left <= right && right <= N)
  {
    if (sum <= S)
    {
      sum = sum + arr[right];
      right++;
      len++;
    }
    else if (sum > S)
    {
      sum = sum - arr[left];
      left++;
      len--;
    }

    if (sum >= S)
    {
      flag = 1;
      if (len < min_len)
        min_len = len;
    }
  }

  if (flag == 0)
    cout << 0;
  else
    cout << min_len;

  return 0;
}