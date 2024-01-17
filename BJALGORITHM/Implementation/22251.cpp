#include <bits/stdc++.h>

using namespace std;

int N, K, P, X;
int max_num[6] = { 0 };
int cur_num[6] = { 0 };
int comp_num[6] = { 0 };
int cnt = 0;
int num_display[10][7] = {{1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

void num_check(int k)
{
  if (k == K)
  {
    int num = 0;
    for (int i = 0; i < K; i++)
    {
      num = (num*10) + comp_num[i];
    }
    if (num > N || num == 0)
      return;

    int dif_LED = 0;
    for (int i = 0; i < K; i++)
    {
      for (int j = 0; j < 7; j++)
      {
        if (num_display[cur_num[i]][j] != num_display[comp_num[i]][j])
          dif_LED++;
      }
    }

    if (dif_LED <= P)
      cnt++;

    return;
  }

  for (int i = 0; i <= 9; i++)
  {
    comp_num[k] = i;
    num_check(k + 1);
  }

  return;
}

int main()
{
  cin >> N >> K >> P >> X;
  int num = X;
  int max = N;

  for (int i = K - 1; i >= 0; i--)
  {
    cur_num[i] = num % 10;
    num = num / 10;
  }

  for (int i = K - 1; i >= 0; i--)
  {
    max_num[i] = max % 10;
    max = max / 10;
  }

  num_check(0);

  cout << cnt - 1;

  return 0;
}