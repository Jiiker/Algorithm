#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  vector<int> x;
  int max_value = 0;
  int min_height = 0;

  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    int num;
    cin >> num;
    x.push_back(num);
  }

  for (int i = 1; i < x.size(); i++)
  {
    if (x[i] - x[i - 1] > max_value)
      max_value = x[i] - x[i - 1];
  }

  min_height = max((max_value + 1) / 2 ,max(x[0] - 0, N - x[x.size() - 1]));

  cout << min_height;

  return 0;
}