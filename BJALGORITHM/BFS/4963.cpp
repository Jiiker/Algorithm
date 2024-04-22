#include <bits/stdc++.h>

using namespace std;

int use_elevator(int F, int S, int G, int U, int D)
{
  int dx[2] = { U, -D };
  int vis[1000005] = { 0 };
  queue<int> Q;

  Q.push(S);
  vis[S] = 1;

  while (!Q.empty())
  {
    int cur = Q.front(); Q.pop();

    for (int dir = 0; dir < 2; dir++)
    {
      int next = cur + dx[dir];

      if (next <= 0 || next > F)
        continue;
      if (vis[next] != 0)
        continue;

      Q.push(next);
      vis[next] = vis[cur] + 1;
    }
  }

  return vis[G] - 1;
}


int main()
{
  int F, S, G, U, D, answer;
  cin >> F >> S >> G >> U >> D;

  answer = use_elevator(F, S, G, U, D);

  if (answer == -1)
    cout << "use the stairs";
  else
    cout << answer;

  return 0;
}