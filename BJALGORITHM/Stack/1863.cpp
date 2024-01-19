#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  stack<int> S;
  int cnt = 0;
  cin >> N;

  S.push(0);
  for (int i = 0; i < N; i++)
  {
    int loc, height;
    cin >> loc >> height;

    while (height < S.top())
    {
      S.pop();
    }

    if (height > S.top())
    {
      cnt++;
      S.push(height);
    }
  }

  cout << cnt;

  return 0;
}