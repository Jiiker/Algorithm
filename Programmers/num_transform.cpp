#include <bits/stdc++.h>

using namespace std;

int solution(int x, int y, int n) {
  int answer = 0;
  int DP[3000005] = { 0 };
  fill(DP, DP+1000005, INT_MAX);
  DP[x] = 0;
  
  for (int i = 0; i <= y; i++) {
    if (DP[i] != INT_MAX) {
      if (DP[i + n] > DP[i]+1)
        DP[i + n] = DP[i]+1;
      if (DP[i * 2] > DP[i]+1)
        DP[i * 2] = DP[i]+1;
      if (DP[i * 3] > DP[i]+1)
        DP[i * 3] = DP[i]+1;
    }
  }
  
  if (DP[y] == INT_MAX)
    answer = -1;
  else
    answer = DP[y];
  
  return answer;
}