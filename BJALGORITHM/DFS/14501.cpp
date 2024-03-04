#include <bits/stdc++.h>

using namespace std;
int max_sum = 0;
void DFS(vector<pair<int, int>> consulting, int day, int N, int sum);

int main() 
{
  int N = 0;
  vector<pair<int, int>> consulting;

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int time, pay;

    cin >> time >> pay;

    consulting.push_back({time, pay});
  }

  DFS(consulting, 0, N, 0);

  cout << max_sum;

  return 0;
}

void DFS(vector<pair<int, int>> consulting, int day, int N, int sum)
{
  if (day >= N)
  {
    if (sum > max_sum)
      max_sum = sum;
    return;
  }

  for (int i = 0; i < 2; i++)
  {
    if (i == 0)
      DFS(consulting, day + 1, N, sum);
    else 
    {
      if (day + consulting[day].first > N)
      {
        DFS(consulting, N, N, sum);
        continue;
      }
      DFS(consulting, day + consulting[day].first, N, sum + consulting[day].second);
    }
  }

  return;
}