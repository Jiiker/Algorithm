#include <bits/stdc++.h>

using namespace std;

int width = 6;
int height = 12;
char board[12][6] = { '.' };
int chain = 0;
bool gameover = 0;

void BFS();
void boom(int cnt, stack<pair<int, int>> S);
void restucturing();

int main()
{
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
      cin >> board[i][j];
  }

  while(1)
  {
    if (gameover == 1)
      break;
    BFS();
  }

  cout << chain;

  return 0;
}

void BFS()
{
  int vis[12][6] = { 0 };
  bool chaining = 0;

  for (int i = 11; i >= 0; i--)
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.')
      {
        int cnt = 0;
        queue<pair<int, int> > Q;
        stack<pair<int, int> > chain_stack;

        Q.push({i, j});
        vis[i][j] = 1;
        while(!Q.empty())
        {
          pair<int, int> cur = Q.front(); Q.pop();
          chain_stack.push(cur);
          cnt++;
          int dx[4] = { 1, 0, -1, 0};
          int dy[4] = { 0, 1, 0, -1};

          for (int dir = 0; dir < 4; dir++)
          {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
              continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != board[i][j])
              continue;
            
            Q.push({nx, ny});
            vis[nx][ny] = 1;
          }
        }

        if (cnt >= 4)
        {
          chaining = 1;
          boom(cnt, chain_stack);
        }
      }
    }
  }

  if (chaining == 0)
  {
    gameover = 1;
    return;
  }  

  chain++;
  restucturing();

  return;
}

void boom(int cnt, stack<pair<int, int>> S)
{
  for (int i = 0; i < cnt; i++)
  {
    pair<int, int> cur = S.top(); S.pop();

    board[cur.first][cur.second] = '.';
  }

  return;
}

void restucturing()
{
  for (int i = 11; i >= 0; i--)
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.')
      {
        if (board[i+1][j] != '.')
          continue;
        for (int k = i + 1; k <= 11; k++)
        {
          if (k == 11 && board[k][j] == '.')
          {
            board[k][j] = board[i][j];
            board[i][j] = '.';
            break;
          }
          if (board[k][j] != '.')
          {
            board[k-1][j] = board[i][j];
            board[i][j] = '.';
            break;
          }
        }
      }
    }
  }
  return;
}