#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  int sum[500][500] = { 0 };
  vector<vector<int>> triangle;
  int max = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    vector<int> temp;

    for (int j = 0; j <= i; j++) {
      int num;

      cin >> num;
      temp.push_back(num);
    }

    triangle.push_back(temp);
  }

  sum[0][0] = triangle[0][0];
  for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      if (sum[i+1][j] < sum[i][j] + triangle[i+1][j])
        sum[i+1][j] = sum[i][j] + triangle[i+1][j];

      if (sum[i+1][j+1] < sum[i][j] + triangle[i+1][j+1])
        sum[i+1][j+1] = sum[i][j] + triangle[i+1][j+1];
    }
  }

  for (int i = 0; i < N; i++) {
    if (max < sum[N-1][i])
      max = sum[N-1][i];
  }

  cout << max;

  return 0;
}