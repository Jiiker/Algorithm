#include <bits/stdc++.h>

using namespace std;

int arr[10][10] = { 0 };
int vis[10] = { 0 };
int N = 0, start_point = 0, sum = 0, min_sum = 9999999;

void Backtracking(int k, int start)
{
  for (int i = 0; i < N; i++)
  {
    if (k == N - 1)
    {
      if (arr[start][start_point] == 0)
        return;

      sum = sum + arr[start][start_point];
      if (sum < min_sum)
        min_sum = sum;

      sum = sum - arr[start][start_point];

      return;
    }
    if (arr[start][i] == 0)
      continue;
    if (vis[i] == 1)
      continue;
    
    vis[i] = 1;
    sum = sum + arr[start][i];
    
    Backtracking(k + 1, i);
    
    vis[i] = 0;
    sum = sum - arr[start][i];
  }

  return;
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> arr[i][j];
  }

  for (int i = 0; i < N; i++)
  {
    start_point = i;
    vis[i] = 1;
    Backtracking(0, i);
    vis[i] = 0;
  }  

  cout << min_sum;

  return 0;
}