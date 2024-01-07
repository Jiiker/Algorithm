#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, string> a, const pair<int, string> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
  int p, m;
  int check_player[300] = { 0 };
  vector<pair<int, string>> player;

  cin >> p >> m;

  for (int i = 0; i < p; i++)
  {
    int lev;
    string nick;

    cin >> lev >> nick;
    player.push_back({lev, nick});
  }

  while (p > 0)
  {
    int standard = 0;
    int temp_size = 0;
    vector<pair<int, string>> temp;
    
    for (int i = 0; i < player.size(); i++)
    {
      if (temp.size() == 0 && check_player[i] == 0)
      {
        standard = player[i].first;
        check_player[i] = 1;
        p--;
        temp.push_back(player[i]);
      }
      else if (check_player[i] == 0 && abs(player[i].first - standard) <= 10)
      {
        check_player[i] = 1;
        p--;
        temp.push_back(player[i]);
      }

      temp_size = temp.size();
      if (temp_size == m)
      {
        sort(temp.begin(), temp.end(), compare);
        cout << "Started!\n";
        for (int j = 0; j < m; j++)
        {
          cout << temp.front().first << ' ' << temp.front().second << '\n';
          temp.erase(temp.begin());
        }
        break;
      }
    }
    if (temp_size > 0 && temp_size != m)
    {
      sort(temp.begin(), temp.end(), compare);
      cout << "Waiting!\n";
      for (int i = 0; i < temp_size; i++)
      {
        cout << temp.front().first << ' ' << temp.front().second << '\n';
        temp.erase(temp.begin());
      }
    }
  }

  return 0;
}