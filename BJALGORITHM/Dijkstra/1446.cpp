#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, D;
  int Dijkstra[10001] = { 0 };
  vector<vector<int>> path;

  cin >> N >> D;

  for (int i = 0; i < N; i++)
  {
    vector<int> temp;
    int st, end, len;

    cin >> st >> end >> len;
    
    temp.push_back(end);
    temp.push_back(st);
    temp.push_back(len);

    path.push_back(temp);
  }
  sort(path.begin(), path.end());

  for (int i = 1; i <= D; i++)
  {
    Dijkstra[i] = i;
    if (Dijkstra[i - 1] + 1 < Dijkstra[i])
      Dijkstra[i] = Dijkstra[i - 1] + 1;

    while (i == path[0][0])
    {
      int st = path[0][1];
      int end = path[0][0];
      int len = path[0][2];
      path.erase(path.begin());

      if (Dijkstra[st] + len < Dijkstra[i])
        Dijkstra[i] = Dijkstra[st] + len;
    }
  }

  cout << Dijkstra[D];

  return 0;
}