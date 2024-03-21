#include <bits/stdc++.h>

using namespace std;
set<int> S;

void calculate_sum(int k, vector<int> elements, int len)
{
  int st = 0;
  int end = k;
  int sum = 0;
  
  while(st < len)
  {
    sum = 0;
    for (int i = st; i < end; i++)
    {
      sum = sum + elements[i];
    }
    
    S.insert(sum);
    st++;
    end++;
  }
  
  return;
}

int solution(vector<int> elements) {
  int answer = 0;
  int len = elements.size();
  
  for (int i = 0; i < len - 1; i++)
  {
    elements.push_back(elements[i]);
  }
  
  for (int i = 1; i <= len; i++)
  {
    calculate_sum(i, elements, len);
  }
  
  answer = S.size();
  
  return answer;
}