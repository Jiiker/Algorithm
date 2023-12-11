#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  vector<pair<int, int>> V;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int weight, height;

    cin >> weight >> height;

    V.push_back({weight, height});
  }

  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if (i == j)
        continue;
      if (V[i].first < V[j].first && V[i].second < V[j].second)
        cnt++;
    }

    cout << cnt + 1 << ' ';
  }

  return 0;
}