#include <bits/stdc++.h>

using namespace std;

int main() {
  int FOS[40] = { 0 };
  int K = 0;
  int D = 0, O = 0;
  int pow = 2;

  cin >> K;
  O = K;
  while (pow < O) {
    O = O - pow;
    pow = pow * 2;
    D++;
  }

  O = O - 1;

  while (D >= 0) {
    if (O % 2 == 0) {
      FOS[D] = 4;
    } else {
      FOS[D] = 7;
    }
  
    O = O / 2;
    D--;
  }

  for (int i = 0; i < 40; i++) {
    if (FOS[i] == 0)
      break;

    cout << FOS[i];
  }

  return 0;
}