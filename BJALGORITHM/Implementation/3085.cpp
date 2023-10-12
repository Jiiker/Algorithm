#include <bits/stdc++.h>

using namespace std;

int N = 0;
char arr[51][51] = { '\0' };
int max_cnt = 0;

void line_check()
{
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    cnt = 1;
    for (int j = 0; j < N; j++)
    {
      if (j == N-1)
      {
        if (cnt > max_cnt)
          max_cnt = cnt;
        break;
      }
      if (arr[i][j] == arr[i][j+1])
        cnt++;
      else
      {
        if (cnt > max_cnt)
          max_cnt = cnt;
        cnt = 1;
      }
        
    }
  }

  for (int i = 0; i < N; i++)
  {
    cnt = 1;
    for (int j = 0; j < N; j++)
    {
      if (j == N-1)
      {
        if (cnt > max_cnt)
          max_cnt = cnt;
      }
      if (arr[j][i] == arr[j+1][i])
        cnt++;
      else
      {
        if (cnt > max_cnt)
          max_cnt = cnt;
        cnt = 1;
      }
    }
  }
}

int main()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> arr[i][j];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (arr[i][j] != arr[i+1][j] && i+1 != N)
      {
        swap(arr[i][j], arr[i+1][j]);
        line_check();
        swap(arr[i][j], arr[i+1][j]);
      }
      if (arr[i][j] != arr[i][j+1] && j+1 != N)
      {
        swap(arr[i][j], arr[i][j+1]);
        line_check();
        swap(arr[i][j], arr[i][j+1]);
      }
    }
  }

  cout << max_cnt;

  return 0;
}