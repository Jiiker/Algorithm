#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 0;
  vector<vector<int>> friends;
  int max_friends = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    vector<int> row;

    for (int j = 0; j < N; j++) {
      char isFriend;

      cin >> isFriend;
      if (isFriend == 'N')
        continue;
      
      row.push_back(j);
    }

    friends.push_back(row);
  }

  for (int i = 0; i < N; i++) {
    set<int> S;

    for (int j = 0; j < friends[i].size(); j++) {
      S.insert(friends[i][j]);

      for (int k = 0; k < friends[friends[i][j]].size(); k++) {
        if (friends[friends[i][j]][k] == i)
          continue;
        S.insert(friends[friends[i][j]][k]);
      }
    }

    if (S.size() > max_friends)
      max_friends = S.size();
  }

  cout << max_friends;

  return 0;
}