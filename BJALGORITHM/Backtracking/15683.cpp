#include <bits/stdc++.h>

using namespace std;

int arr[8][8] = { 0 };
int N = 0, M = 0;
int num_cctv = 0;
int dir_cctv[8] = { 0 };
int dx[7] = {0, 1, 0, -1, 0, 1, 0 };
int dy[7] = {1, 0, -1, 0, 1, 0, -1 };
int minimum = 64;

void set_dir_cctv(int num);
void set_cctv();
void draw_sight(int row, int col, int kind, int dir, int arr_copy[][8]);

int main()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] > 0 && arr[i][j] < 6)
        num_cctv++;
    }
  }

  set_dir_cctv(0);

  cout << minimum;

  return 0;
}

void set_dir_cctv(int num)
{
  
  if (num == num_cctv)
  {
    set_cctv();
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    dir_cctv[num] = i;
    set_dir_cctv(num + 1);
  }
  return;
}

void set_cctv()
{
  int arr_copy[8][8] = { 0 };
  int cnt = 0;
  int cctv_cnt = 0;
  copy(&arr[0][0], &arr[0][0] + 64, &arr_copy[0][0]);
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (arr[i][j] > 0 && arr[i][j] < 6)
      {
        draw_sight(i, j, arr[i][j], dir_cctv[cctv_cnt], arr_copy);
        cctv_cnt++;
      }
    }
  }    

  for (int n = 0; n < N; n++)
  {
    for (int m = 0; m < M; m++)
    {
      if (arr_copy[n][m] == 0)
        cnt++;
    }
  }

  if (cnt < minimum)
    minimum = cnt;

  return;
}

void draw_sight(int row, int col, int kind, int dir, int arr_copy[][8])
{
  int i = row;
  int j = col;

  if (kind < 6)
  {
    while (!(i < 0 || j < 0 || i >= N || j >= M))
    {
      i += dx[0 + dir];
      j += dy[0 + dir];
      if (arr_copy[i][j] == 6)
        break;
      if (arr_copy[i][j] != 0)
        continue;
      if (!(i < 0 || j < 0 || i >= N || j >= M))
        arr_copy[i][j] = 9;
    }
  }

  i = row;
  j = col;
  if (kind == 5)
  {
    while (!(i < 0 || j < 0 || i >= N || j >= M))
    {
      i += dx[1 + dir];
      j += dy[1 + dir];

      if (arr_copy[i][j] == 6)
        break;
      if (arr_copy[i][j] != 0)
        continue;
      if (!(i < 0 || j < 0 || i >= N || j >= M))
        arr_copy[i][j] = 9;
    }
  }

  i = row;
  j = col;
  if (kind == 2 || kind == 4 || kind == 5)
  {
    while (!(i < 0 || j < 0 || i >= N || j >= M))
    {
      i += dx[2 + dir];
      j += dy[2 + dir];
      if (arr_copy[i][j] == 6)
        break;
      if (arr_copy[i][j] != 0)
        continue;
      if (!(i < 0 || j < 0 || i >= N || j >= M))
        arr_copy[i][j] = 9;
    }
  }

  i = row;
  j = col;
  if (kind == 3 || kind == 4 || kind == 5)
  {
    while (!(i < 0 || j < 0 || i >= N || j >= M))
    {
      i += dx[3 + dir];
      j += dy[3 + dir];
      if (arr_copy[i][j] == 6)
        break;
      if (arr_copy[i][j] != 0)
        continue;
      if (!(i < 0 || j < 0 || i >= N || j >= M))
        arr_copy[i][j] = 9;
    }
  }

  return;
}