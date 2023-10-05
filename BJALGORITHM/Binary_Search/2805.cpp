#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1000005] = { 0 };

void binarysearch(int en);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int max = 0;
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
    if (max < arr[i])
      max = arr[i];
  }

  binarysearch(max);

  return 0;
}

void binarysearch(int en)
{
  int st = 0;
  while (st <= en)
  {
    int mid = (st + en) / 2;
    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
      int log = arr[i] - mid;
      if (log > 0)
        sum = sum + log;
    }

    if (sum >= M)
    {
      st = mid + 1;
    }
    else
    {
      en = mid - 1;
    }
  }

  cout << en;
}