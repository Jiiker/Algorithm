#include <bits/stdc++.h>

using namespace std;
int N, L, R;
int arr[51][51] = { 0 };
bool isMoved = false;

void pop_move(vector<pair<int, int>> Allies)
{
  int sum = 0;
  int value = 0;
  for (int i = 0; i < Allies.size(); i++)
  {
    sum = sum + arr[Allies[i].first][Allies[i].second];
  }

  value = sum / Allies.size();

  for (int i = 0; i < Allies.size(); i++)
  {
    arr[Allies[i].first][Allies[i].second] = value;
  }

  return;
}

void choose_country()
{
  int vis[50][50] = { 0 };
  int dx[4] = { 1, 0, -1, 0 };
  int dy[4] = { 0, 1, 0, -1 };
  queue<pair<int, int>> Q;
  vector<pair<int, int>> Allies;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (vis[i][j] == 0 && 
      ((abs(arr[i][j] - arr[i][j+1]) <= R && abs(arr[i][j] - arr[i][j+1]) >= L && j < N - 1) || 
      (abs(arr[i][j] - arr[i+1][j]) <= R && abs(arr[i][j] - arr[i+1][j]) >= L && i < N - 1)))
      {
        isMoved = true;
        Q.push({i, j});
        vis[i][j] = 1;
        Allies.push_back({i, j});

        while(!Q.empty())
        {
          pair<int, int> cur = Q.front(); Q.pop();

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
              continue;
            if (vis[nx][ny] == 1)
              continue;
            if (abs(arr[nx][ny] - arr[cur.first][cur.second]) < L || abs(arr[nx][ny] - arr[cur.first][cur.second]) > R)
              continue;
            
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            Allies.push_back({nx, ny});
          }
        }
        pop_move(Allies);
        Allies.clear();
      }
    }
  }

  return;
}


int main()
{
  int count = 0;
  cin >> N >> L >> R;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
    }
  }

  while(1)
  {
    isMoved = false;

    choose_country();

    if (isMoved)
      count++;
    else
      break;
  }
  
  cout << count;

  return 0;
}