#include <bits/stdc++.h>

using namespace std;

string num_to_string (int n) {
  string str;

  while (n > 0) {
    char num = (n % 10) + 48;
    n = n / 10;
    str = num + str;
  }

  while (str.length() < 7) {
    str = '0' + str;
  }

  return str;
}

int main() {
  int N, K;
  vector<pair<string, pair<int, int>>> V;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int C, G, S, B;
    string result;

    cin >> C >> G >> S >> B;

    result = num_to_string(G) + num_to_string(S) + num_to_string(B);

    V.push_back({result, {C, 0}});
  }

  sort(V.begin(), V.end(), greater<pair<string, pair<int, int>>>());

  for (int i = 0; i < N; i++) {
    

    if (i == 0) {
      V[i].second.second = 1;
      if (V[i].second.first == K) {
        cout << V[i].second.second;
        break;
      }
    }

    if (V[i-1].first == V[i].first) {
      V[i].second.second = V[i-1].second.second;
    } else {
      V[i].second.second = i + 1;
    }

    if (V[i].second.first == K) {
        cout << V[i].second.second;
        break;
    }
  }

  return 0;
}