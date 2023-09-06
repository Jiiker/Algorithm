#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 0;
  cin >> T;

  for (int t = 0; t < T; t++)
  {
    int N = 0, fail = 0; 
    vector<pair<int, int>> V;
    cin >> N;
    for (int n = 0; n < N; n++)
    {
      int paper, intv;
      cin >> paper >> intv;

      V.push_back({paper, intv});
    }

    sort(V.begin(), V.end());

    int stand = 0;

    for (int i = 1; i < N; i++)
    {
      if (V[stand].second < V[i].second)
        fail++;
      else
        stand = i;
    }

    cout << N - fail << '\n';
  }

  return 0;
}