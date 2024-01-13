#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  vector<vector<pair<int,int>>> V;
  int cost[50000] = { 0 };
  int vis[50000] = { 0 };
  queue<int> Q;

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    vector<pair<int, int>> temp;
    V.push_back(temp);
    cost[i] = INT_MAX;
  }

  for (int i = 0; i < M; i++)
  {
    int st, end, pay;
    cin >> st >> end >> pay;
    V[st - 1].push_back({end - 1, pay});
    V[end - 1].push_back({st - 1, pay});
  }

  Q.push(0);
  cost[0] = 0;
  vis[0] = 1;
  while(!Q.empty())
  {
    int cur = Q.front(); Q.pop();
    for (int i = 0; i < V[cur].size(); i++)
    {
      if (V[cur][i].first == N)
      {
        if (cost[cur] + V[cur][i].second < cost[V[cur][i].first])
          cost[V[cur][i].first] = cost[cur] + V[cur][i].second;
        break;
      }
      
      if (cost[cur] + V[cur][i].second < cost[V[cur][i].first])
      {
        cost[V[cur][i].first] = cost[cur] + V[cur][i].second;
        Q.push(V[cur][i].first);
      }
    }
  }

  cout << cost[N - 1];

  return 0;
}