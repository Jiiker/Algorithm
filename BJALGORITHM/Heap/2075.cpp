#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  vector<int> V;

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int num;
      cin >> num;
      V.push_back(num);
    }

    make_heap(V.begin(), V.end(), greater<>());
    while (V.size() > i + 1)
    {
      pop_heap(V.begin(), V.end(), greater<>());
      V.pop_back();
    }
  }

  make_heap(V.begin(), V.end(), greater<>());

  cout << V.front();

  return 0;
}