#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, d, k, c;
  int sushi_belt[35000] = { 0 };
  int max_cnt = 0;

  cin >> N >> d >> k >> c;

  for (int i = 0; i < N; i++)
  {
    cin >> sushi_belt[i];
  }
  for (int i = N; i < N + k; i++)
  {
    sushi_belt[i] = sushi_belt[i - N];
  }

  for (int i = 0; i < N; i++)
  {
    int check_sushi[3000] = { 0 };
    int cnt = 0;
    bool coupon = false;

    for (int j = i; j < i + k; j++)
    {
      if (check_sushi[sushi_belt[j]] == 0)
      {
        check_sushi[sushi_belt[j]] = 1;
        cnt++;
      }
      if (sushi_belt[j] == c)
        coupon = true;
    }

    if (coupon == false)
      cnt++;

    if (cnt > max_cnt)
      max_cnt = cnt;
  }

  cout << max_cnt;

  return 0;
}