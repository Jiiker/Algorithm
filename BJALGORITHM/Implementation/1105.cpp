#include <bits/stdc++.h>

using namespace std;

int main () {
  string L, R;
  int cnt = 0;

  cin >> L >> R;

  if (L.length() < R.length()) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < L.length(); i++) {
    if (L[i] == R[i]) {
      if (L[i] == '8')
        cnt++;
    } else break;
  }

  cout << cnt;

  return 0;
}