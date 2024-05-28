#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
  vector<int> answer;
  int devide = n;
  
  if (n > s)
    answer.push_back(-1);
  else
  {
    for (int i = 0; i < n; i++)
    {
        answer.push_back(s/devide);
        s = s - (s/devide);
        devide--;
    }
  }
  
  sort(answer.begin(), answer.end());
  
  return answer;
}