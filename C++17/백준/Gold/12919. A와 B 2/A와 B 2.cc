#include <bits/stdc++.h>

using namespace std;
bool isFinished = false;

bool isIncluded(string s, string l) {
  if (l.find(s) != string::npos) {
    return true;
  }

  reverse(l.begin(), l.end());

  if (l.find(s) != string::npos) {
    return true;
  }

  return false;
}

void dfs(string str, string dest) {
  if (isFinished) return;

  if (str.length() == dest.length()) {
    if (str == dest) {
      isFinished = true;
    }

    return;
  }

  if (!isIncluded(str, dest)) return;

  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      string newStr;
      newStr = str + 'A';

      dfs(newStr, dest);
    } else if (i == 1) {
      string newStr;
      newStr = str + 'B';
      reverse(newStr.begin(), newStr.end());

      dfs(newStr, dest);
    }
  }

  return;
}

int main() {
  string str, dest;

  cin >> str >> dest;

  dfs(str, dest);

  if (isFinished) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}