#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, k;
  queue<int> Q;
  int del_arr[5000];

  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    Q.push(i);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k - 1; j++)
    {
      int num = Q.front(); Q.pop();
      Q.push(num);
    }
    del_arr[i] = Q.front(); Q.pop();
  }

  cout << '<';
  for (int i = 0; i < n - 1; i++)
    cout << del_arr[i] << ", ";
  cout << del_arr[n-1] << '>';

  return 0;
}