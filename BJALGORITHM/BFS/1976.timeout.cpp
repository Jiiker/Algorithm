#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int vis[200] = { 0 };
int idx = 0;
int path[200][200] = { 0 };
int N, M;
vector<int> rute;
bool suc = false;

void BFS(int cur, int k)
{
  if (k == M)
  {
    suc = true;
    for (int i = 0; i < N; i++)
    {
      if (vis[i] == 0)
        suc = false;
    }

    return;
  }

  for (int n = 0; n < N; n++)
  {
    if (path[cur][n] == 0)
      continue;
    
    if (n == rute[idx])
    {
      vis[idx] = 1;
      idx++;
    }
    BFS(n, k+1);
  }

  return;
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> path[i][j];
    }
  }

  for (int i = 0; i < M; i++)
  {
    int num;
    cin >> num;
    rute.push_back(num - 1);
  }

  vis[idx] = 1;
  idx++;
  BFS(rute[0], 0);

  if (suc)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}