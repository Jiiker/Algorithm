#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  string str;
  int eat[20000] = { 0 };
  int cnt = 0;

  cin >> N >> K >> str;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'H')
      continue;

    int start, end;
    if (i - K < 0) {
      start = 0;
    } else {
      start = i - K;
    }

    if (i + K > N - 1) {
      end = N - 1;
    } else {
      end = i + K;
    }

    for (int j = start; j <= end; j++) {
      if (str[j] == 'H' && eat[j] == 0) {
        eat[j] = 1;
        cnt++;
        break;
      }
    }
  }

  cout << cnt;

  return 0;
}