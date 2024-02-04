#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
  int answer = 0;
  int min = INT_MAX;
  int left = 0, right = k - 1;
  priority_queue<pair<int, int>> pq;
  
  for (int i = left; i <= right; i++)
  {
    pq.push({stones[i], i});
  }
  
  min = pq.top().first;
  left++;
  right++;
  
  while (right < stones.size())
  {
    pq.push({stones[right], right});
    
    while (pq.top().second < left)
    {
      pq.pop();
    }
    
    if (pq.top().first < min)
      min = pq.top().first;
    
    left++;
    right++;
  }
  
  answer = min;

  return answer;
}