#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  int first_row[101] = { 0 };
  int second_row[101] = { 0 };
  int cnt_second_row[101] = { 0 };
  queue<int> Q;
  queue<int> answer;

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    first_row[i] = i;
    cin >> second_row[i];

    cnt_second_row[second_row[i]]++;
  }

  for (int i = 1; i <= N; i++)
  {
    if (cnt_second_row[i] == 0)
      Q.push(i);
  }

  while(!Q.empty())
  {
    int cur = Q.front(); Q.pop();

    first_row[cur] = 0;
    
    cnt_second_row[second_row[cur]]--;
    if (cnt_second_row[second_row[cur]] == 0)
      Q.push(second_row[cur]);

    second_row[cur] = 0;
  }

  for (int i = 1; i <= N; i++)
  {
    if (first_row[i] != 0)
      answer.push(first_row[i]);
  }

  cout << answer.size() << '\n';
  while(!answer.empty())
  {
    cout << answer.front() << '\n';
    answer.pop();
  }

  return 0;
}
