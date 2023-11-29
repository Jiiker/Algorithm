#include <bits/stdc++.h>

using namespace std;
int path[1001][1001] = { 0 };
int N, M, X;
int max_total_fee = 0;
int minimal_fee = INT_MAX;

void calculate_minimal_fee(int start, int dest, int sum);

int main()
{
  cin >> N >> M >> X;

  for (int i = 0; i < M; i++)
  {
    int st, end, time;
    cin >> st >> end >> time;
    path[st - 1][end - 1] = time;
  }

  for (int n = 0; n < N; n++)
  {
    int total_fee = 0;

    calculate_minimal_fee(n, X - 1, 0);
    total_fee += minimal_fee;
    minimal_fee = INT_MAX;
    calculate_minimal_fee(X - 1, n, 0);
    total_fee += minimal_fee;

    if (total_fee > max_total_fee)
      max_total_fee = total_fee;
  }

  return 0;
}

void calculate_minimal_fee(int start, int dest, int sum)
{
  if (start == dest)
  {
    if (sum < minimal_fee)
      minimal_fee = sum;
    
    return;
  }

  for (int i = 0; i < N; i++)
  {
    if (path[start][i] == 0)
      continue;
    
    int next = i;
    int new_sum = sum + path[start][i];
    calculate_minimal_fee(next, dest, new_sum);
  }

  return;
}