#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, X;
  int vis[250005];
  int left = 0, right = 0;
  int max = 0, cnt = 0, sum = 0;
  cin >> N >> X;

  for (int i = 0; i < N; i++)
    cin >> vis[i];
  for (int i = 0; i < X; i++)
    sum += vis[i];

  right = left + X;
  max = sum;
  cnt++;
  
  while (right <= N)
  {
    sum = sum + vis[right] - vis[left];

    if (sum == max)
      cnt++;
    
    if (sum > max)
    {
      max = sum;
      cnt = 1;
    }

    left++;
    right++;
  }

  if (max == 0)
  {
    cout << "SAD";
    return 0;
  }

  cout << max << '\n' << cnt;

  return 0;
}