#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  int result[100005];
  fill(result, result + 100005, -1);
  result[0] = 0;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int caf = 0;

    cin >> caf;

    for (int j = K; j >= 0; j--) {
      if (result[j - caf] != -1 && j - caf >= 0) {
        if (result[j] == -1 || result[j - caf] + 1 < result[j]) {
          result[j] = result[j - caf] + 1;
        }
      } 
    }
  }

  cout << result[K];

  return 0;
}