#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  int sum = 0;
  int max = -100000000;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;

    sum += num;

    if (sum > max) {
      max = sum;
    }

    if (sum < 0) {
      sum = 0;
    }
  }

  cout << max;

  return 0;
}