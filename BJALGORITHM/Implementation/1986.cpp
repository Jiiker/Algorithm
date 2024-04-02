#include <bits/stdc++.h>

using namespace std;
char board[1000][1000];
int cnt = 1000 * 1000;
int n, m;
int q_dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int q_dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int k_dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int k_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void knight_check(vector<pair<int, int>> K) 
{
  for (int i = 0; i < K.size(); i++)
  {
    pair<int, int> cur = K[i];

    for (int dir = 0; dir < 8; dir++)
    {
      int nx = cur.first + k_dx[dir];
      int ny = cur.second + k_dy[dir];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (board[nx][ny] == 'K' || board[nx][ny] == 'P' || board[nx][ny] == 'Q' || board[nx][ny] == 'D')
        continue;
      
      board[nx][ny] = 'D';
      cnt--;
    }
  }
}

void queen_check(vector<pair<int, int>> Q)
{
  for (int i = 0; i < Q.size(); i++)
  {
    pair<int, int> cur = Q[i];

    for (int dir = 0; dir < 8; dir++)
    {
      int k = 1;
      while (1)
      {
        int nx = cur.first + (k * q_dx[dir]);
        int ny = cur.second + (k * q_dy[dir]);

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          break;
        if (board[nx][ny] == 'K' || board[nx][ny] == 'P' || board[nx][ny] == 'Q')
          break;
        if (board[nx][ny] == 'D')
          cnt++;
        
        board[nx][ny] = 'D';
        cnt--;
        k++;
      }
    }
  }

  return;
}

int main()
{
  int num_q, num_k, num_p;
  vector<pair<int, int>> queen;
  vector<pair<int, int>> knight;
  cin >> n >> m;

  cnt = n * m;

  cin >> num_q;
  for (int i = 0; i < num_q; i++)
  {
    int x, y;
    cin >> x >> y;

    board[x-1][y-1] = 'Q';
    cnt--;
    queen.push_back({x - 1, y - 1});
  }

  cin >> num_k;
  for (int i = 0; i < num_k; i++)
  {
    int x, y;
    cin >> x >> y;

    board[x-1][y-1] = 'K';
    cnt--;
    knight.push_back({x - 1, y - 1});
  }

  cin >> num_p;
  for (int i = 0; i < num_p; i++)
  {
    int x, y;
    cin >> x >> y;

    board[x-1][y-1] = 'P';
    cnt--;
  }
  
  queen_check(queen);
  knight_check(knight);

  cout << cnt;

  return 0;
}