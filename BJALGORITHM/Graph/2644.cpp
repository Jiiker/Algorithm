#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, p1, p2;
  vector<int> relation[100];
  int vis[100];
  queue<int> Q;

  fill(vis, vis + 100, -1);
  
  cin >> n >> p1 >> p2 >> m;

  for (int i = 0; i < m; i++)
  {
    int st, end;
    cin >> st >> end;

    relation[st].push_back(end);
    relation[end].push_back(st);
  }

  Q.push(p1);
  vis[p1] = 0;

  while (!Q.empty())
  {
    int cur = Q.front(); Q.pop();

    for (int i = 0; i < relation[cur].size(); i++)
    {
      int next = relation[cur][i];

      if (vis[next] != -1)
        continue;
      
      vis[next] = vis[cur] + 1;
      Q.push(next);
    }
  }

  cout << vis[p2];

  return 0;
}