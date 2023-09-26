#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  int steps[305] = { 0 };
  vector<int> one_step;
  vector<int> two_step;

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> steps[i];

  one_step.push_back(steps[0]);
  one_step.push_back(steps[0]+steps[1]);
  two_step.push_back(0);
  two_step.push_back(steps[1]);

  for (int i = 2; i < N; i++)
  {
    one_step.push_back(two_step[i-1]+steps[i]);
    if (one_step[i-2] > two_step[i-2])
      two_step.push_back(one_step[i-2]+steps[i]);
    else
      two_step.push_back(two_step[i-2]+steps[i]);
  }

  cout << (one_step[N-1] > two_step[N-1] ? one_step[N-1] : two_step[N-1]);

  return 0;
}