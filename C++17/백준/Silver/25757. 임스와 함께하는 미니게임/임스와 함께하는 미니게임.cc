#include <bits/stdc++.h>

using namespace std;


//Y : 2명
//F : 3명
//O : 4명
int main() {
  int N, P;
  char G;
  int cnt = 1;
  int games = 0;
  set<string> S;

  cin >> N >> G;

  if (G == 'Y') {
    P = 2;
  } else if (G == 'F') {
    P = 3;
  } else if (G == 'O') {
    P = 4;
  }

  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;

    S.insert(name);
  }

  cout << S.size() / (P - 1);

  return 0;
}