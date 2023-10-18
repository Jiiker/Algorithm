#include <bits/stdc++.h>

using namespace std;
int room[50][50] = { 0 };
int R, C, T;

void diffusion();
void purification();

int main()
{
  int sum = 0;
  cin >> R >> C >> T;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
      cin >> room[i][j];
  }

  for (int time = 0; time < T; time++)
  {
    diffusion();
    purification();
  }

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (room[i][j] > 0)
        sum = sum + room[i][j];
    }
  }

  cout << sum;

  return 0;
}

void diffusion()
{
  int dup_room[50][50] = { 0 };
  copy(&room[0][0], &room[0][0] + (50*50), &dup_room[0][0]);

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (room[i][j] >= 1)
      {
        int dx[4] = { 1, 0, -1, 0};
        int dy[4] = { 0, 1, 0, -1};

        for (int dir = 0; dir < 4; dir++)
        {
          int nx = i + dx[dir];
          int ny = j + dy[dir];

          if (nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;
          if (dup_room[nx][ny] == -1)
            continue;
          
          dup_room[nx][ny] = dup_room[nx][ny] + (room[i][j] / 5);
          dup_room[i][j] = dup_room[i][j] - (room[i][j] / 5);
        }
      }
    }
  }

  copy(&dup_room[0][0], &dup_room[0][0] + (50*50), &room[0][0]);
}

void purification()
{
  int flag = 0;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (room[i][j] == -1 && flag == 0)
      {
        int nx = i - 1, ny = j;
        flag = 1;
        while (nx >= 0)
        {
          if (nx == i - 1)
            room[nx][ny] = 0;
          else
            room[nx+1][ny] = room[nx][ny];
          nx--; 
        }
        nx++;
        ny++;
        while (ny < C)
        {
          room[nx][ny-1] = room[nx][ny];
          ny++;
        }
        ny--;
        nx++;
        while (nx <= i)
        {
          room[nx-1][ny] = room[nx][ny];
          nx++;
        }
        nx--;
        ny--;
        while (ny > j)
        {
          room[nx][ny + 1] = room[nx][ny];
          ny--;
        }
        room[i][j+1] = 0;
      }
      else if (room[i][j] == -1)
      {
        int nx = i + 1, ny = j;

        while (nx < R)
        {
          if (nx == i + 1)
            room[nx][ny] = 0;
          else
            room[nx-1][ny] = room[nx][ny];
          nx++; 
        }
        nx--;
        ny++;
        while (ny < C)
        {
          room[nx][ny-1] = room[nx][ny];
          ny++;
        }
        ny--;
        nx--;
        while (nx >= i)
        {
          room[nx+1][ny] = room[nx][ny];
          nx--;
        }
        nx++;
        ny--;
        while (ny > j)
        {
          room[nx][ny + 1] = room[nx][ny];
          ny--;
        }
        room[i][j+1] = 0;
      }
    }
  }
}