#include <bits/stdc++.h>

using namespace std;
int N, C;
vector<int> home;
int answer = 0;

bool check_possible(int dist)
{
  vector<int> wifi;

  wifi.push_back(home[0]);
  for (int i = 1; i < N; i++)
  {
    if (home[i] - wifi.back() >= dist)
      wifi.push_back(home[i]);

    if (wifi.size() == C)
    {
      if (dist > answer)
        answer = dist;
      return true;
    }
  }

  return false;
}

int main()
{
  int dist = 1;
  int max_dist = 0;
  
  cin >> N >> C;

  for (int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    home.push_back(num);
  }

  sort(home.begin(), home.end());
  max_dist = home.back() - home.front();

  while(dist <= max_dist)
  {
    int mid = (dist + max_dist) / 2;

    if (check_possible(mid))
      dist = mid + 1;
    else
      max_dist = mid - 1;
  }

  cout << answer;

  return 0;
}