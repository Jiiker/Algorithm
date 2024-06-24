#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> barn[20005];
  int N, M;
  int vis[20005];
  int max = 0, max_cnt = 0, max_value = 0;
  queue<int> Q;

  fill(vis, vis + 20005, -1);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;

    cin >> from >> to;

    barn[to].push_back(from);
    barn[from].push_back(to);
  }

  Q.push(1);
  vis[1] = 0;

  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();

    for (int dir = 0; dir < barn[cur].size(); dir++) {
      if (vis[barn[cur][dir]] != -1)
        continue;
      
      Q.push(barn[cur][dir]);
      vis[barn[cur][dir]] = vis[cur] + 1;
      if (vis[barn[cur][dir]] > max) {
        max = vis[barn[cur][dir]];
        max_value = barn[cur][dir];
        max_cnt = 1;
      }
      else if (vis[barn[cur][dir]] == max) {
        if (barn[cur][dir] < max_value)
          max_value = barn[cur][dir];
        max_cnt++;
      }
    }
  }

  cout << max_value << ' ' << max << ' ' << max_cnt;

  return 0;
}