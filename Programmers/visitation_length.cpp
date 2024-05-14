#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
  int answer = 0;
  set<pair<pair<int,int>, pair<int,int>>> S;
  int x = 5, y = 5;
  int prev_x = 5, prev_y = 5;
  
  for (int i = 0; i < dirs.length(); i++) {
    char cmd = dirs[i];
    
    if (cmd == 'U') {
      if (y-1 < 0)
          continue;
      y--;
    } else if (cmd == 'D') {
      if (y+1 > 10)
          continue;
      y++;
    } else if (cmd == 'R') {
      if (x+1 > 10)
          continue;
      x++;
    } else {
      if (x-1 < 0)
          continue;
      x--;
    }
    
    S.insert({{prev_x, prev_y},{x,y}});
    S.insert({{x,y}, {prev_x, prev_y}});
    
    prev_x = x;
    prev_y = y;
  }
  
  answer = S.size() / 2;
  
  return answer;
}