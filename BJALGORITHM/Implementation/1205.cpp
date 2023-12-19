#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, score, P;
  int cnt = 1, cnt_score = 1;
  priority_queue<int, vector<int>> pq;

  cin >> N >> score >> P;

  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    pq.push(num);
  }

  while(!pq.empty())
  {
    int cur = pq.top(); pq.pop();
    if (cur > score)
    {
      cnt++;
      cnt_score++;
    }
    else if (cur == score)
    {
      cnt++;
    }
    else
      break;
  }

  if (cnt <= P)
    cout << cnt_score;
  else
    cout << -1;

  return 0;
}