#include <bits/stdc++.h>

using namespace std;
int path[100][100] = { 0 };
int isConnected[100][100] = { 0 };
int N = 0;

void check_connection(int k)
{
  stack<int> S;
  int isUsed[100][100] = { 0 };

  S.push(k);
  while(!S.empty())
  {
    int cur = S.top(); S.pop();

    for (int dest = 0; dest < N; dest++)
    {
      if (path[cur][dest] == 0 || isUsed[cur][dest] == 1)
        continue;
      
      S.push(dest);
      isUsed[cur][dest] = 1;
      isConnected[k][dest] = 1;
    }
  }
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> path[i][j];
    }
  }

  for (int i = 0; i < N; i++)
  {
    check_connection(i);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << isConnected[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}