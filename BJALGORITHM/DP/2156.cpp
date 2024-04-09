#include <bits/stdc++.h>

using namespace std;

int main()
{
  int DP[10005] = { 0 };
  int n = 0;
  int wine[10005] = { 0 };

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> wine[i];
  }

  DP[0] = wine[0];
  DP[1] = wine[0] + wine[1];
  DP[2] = max(max(DP[1], wine[0] + wine[2]), wine[1]+wine[2]);

  for (int i = 3; i < n; i++)
  {
    DP[i] = max(max(DP[i-3]+wine[i-1]+wine[i], DP[i-2]+wine[i]), DP[i-1]);
  }

  cout << DP[n-1];

  return 0;
}