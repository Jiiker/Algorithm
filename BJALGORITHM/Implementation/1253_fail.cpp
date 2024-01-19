#include <bits/stdc++.h>

using namespace std;
vector<int> num;
int cnt = 0;

void two_pointer(int n, int idx, int st, int end)
{
  if (st >= end)
    return;
  
  if (idx == st)
    return;
  if (idx == end)
    return;

  if (n > num[st] + num[end])
    two_pointer(n, idx, st, end - 1);
  if (n < num[st] + num[end])
    two_pointer(n, idx, st + 1, end);
  if (n == num[st] + num[end])
  {
    cnt++;
    return;
  }
  return;
}

int main()
{
  
  int N = 0;
  
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int temp;
    cin >> temp;
    num.push_back(temp);
  }

  sort(num.begin(), num.end());

  for (int i = 0; i < N; i++)
  {
    int I = i;
    while (I+1 < N && num[i] == num[i+1])
    {
      I++;
    }
    two_pointer(num[i], i, 0, N - 1);
  }

  cout << cnt;

  return 0;
}