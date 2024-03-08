#include <bits/stdc++.h>

using namespace std;
int N = 0;
int synergy[20][20] = { 0 };
int min_syn = INT_MAX;

void calculate_synergy(int team[20])
{
  vector<int> team1;
  vector<int> team2;
  int team1_syn = 0;
  int team2_syn = 0;

  for (int i = 0; i < N; i++)
  {
    if (team[i] == 0)
      team1.push_back(i);
    else
      team2.push_back(i);
  }

  for (int i = 0; i < team1.size(); i++)
  {
    for (int j = 0; j < team1.size(); j++)
    {
      if (i == j)
        continue;
      team1_syn = team1_syn + synergy[team1[i]][team1[j]];
    }
  }

  for (int i = 0; i < team2.size(); i++)
  {
    for (int j = 0; j < team2.size(); j++)
    {
      if (i == j)
        continue;
      team2_syn = team2_syn + synergy[team2[i]][team2[j]];
    }
  }

  if (abs(team1_syn - team2_syn) < min_syn)
    min_syn = abs(team1_syn - team2_syn);
  
  return;
}

void split_team(int team[20], int k, int cnt)
{
  if (k >= N)
    return;
  if (cnt == N / 2)
  {
    calculate_synergy(team);
    return;
  }

  for (int i = 0; i < 2; i++)
  {
    if (i == 0)
      split_team(team, k + 1, cnt);
    
    else
    {
      team[k] = 1;
      split_team(team, k + 1, cnt + 1);
      team[k] = 0;
    }
  }

  return;
}

int main()
{
  cin >> N;
  int team[20] = { 0 };

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> synergy[i][j];
  }

  split_team(team, 0, 0);

  cout << min_syn;

  return 0;
}