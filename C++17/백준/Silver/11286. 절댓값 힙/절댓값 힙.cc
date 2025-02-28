#include <bits/stdc++.h>

using namespace std;

struct Node {
  int abs_num, num;

  bool operator<(const Node n) const {
    if (abs_num == n.abs_num) {
      return num > n.num;
    } else {
      return abs_num > n.abs_num;
    }
  }
};

int main() {
  int N = 0;
  cin >> N;

  priority_queue<Node> pq;

  for (int i = 0; i < N; i++) {
    int num;

    cin >> num;

    if (num != 0) {
      pq.push({abs(num), num});
    } else {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        int temp = pq.top().num;
        pq.pop();
        cout << temp << '\n';
      }
    }    
  }

  return 0;
}