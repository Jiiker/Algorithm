#include <bits/stdc++.h>

using namespace std;
int N = 0;
int arr[8] = { 0 };
int result[8] = { 0 };
int check[8] = { 0 };
int max_value = 0;

void back_tracking(int k) {
  if (k == N) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
      sum += abs(result[i] - result[i+1]);
    }

    if (sum > max_value)
      max_value = sum;

    return;
  }

  for (int i = 0; i < N; i++) {
    if (check[i] == 1)
      continue;

    result[k] = arr[i];
    check[i] = 1;
    back_tracking(k + 1);
    check[i] = 0;
    result[k] = 0;
  }

  return;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  back_tracking(0);

  cout << max_value;

  return 0;
}