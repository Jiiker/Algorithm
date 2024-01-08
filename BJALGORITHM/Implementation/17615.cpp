#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  int arr[500000] = { 0 };
  int red = 0, blue = 0;
  int left_side = 0, right_side = 0;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    char color;
    cin >> color;
    if (color == 'R')
    {
      red++;
    }
    else
    {
      blue++;
      arr[i] = 1;
    }
  }


  int cnt = 0;
  for (int i = 0; i < 500000; i++)
  {
    if (arr[i] != arr[0])
      break;
    cnt++;
  }

  if (arr[0] == 0)
    left_side = min(red - cnt, blue);
  else
    left_side = min(red, blue - cnt);

  cnt = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    if (arr[i] != arr[N-1])
      break;
    cnt++;
  }

  if (arr[N-1] == 0)
    right_side = min(red - cnt, blue);
  else
    right_side = min(red, blue - cnt);
  
  cout << min(left_side, right_side);

  return 0;
}