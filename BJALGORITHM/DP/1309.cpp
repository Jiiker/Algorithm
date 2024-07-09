#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 0;
  vector<pair<pair<int, int>, int>> DP;

  cin >> N;

  DP.push_back({{1, 1}, 1});

  for (int i = 0; i < N; i++) {
    int x, y, z;

    x = (DP[i].first.first + DP[i].first.second + DP[i].second) % 9901;
    y = (DP[i].first.first + DP[i].second) % 9901;
    z = (DP[i].first.first + DP[i].first.second) % 9901;

    DP.push_back({{x, y}, z});
  }

  cout << (DP[N-1].first.first + DP[N-1].first.second + DP[N-1].second) % 9901;

  return 0;
}