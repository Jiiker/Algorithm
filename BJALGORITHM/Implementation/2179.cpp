#include <bits/stdc++.h>

using namespace std;
int max_cnt = 0;
string most_sim_word1;
string most_sim_word2;

void compare(string str1, string str2)
{
  int i = 0;
  if (str1[i] == str2[i])
  {
    int cnt = 0;
    while (i < str1.length() && i < str2.length())
    {
      if (str1[i] == str2[i])
        cnt++;
      else
        break;
      if (cnt > max_cnt)
      {
        max_cnt = cnt;
        most_sim_word1 = str1;
        most_sim_word2 = str2;
      }
      i++;
    }
  }

  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> words;
  int n = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    words.push_back(str);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (words[i].length() <= max_cnt || words[j].length() <= max_cnt)
        continue;
      compare(words[i], words[j]);
    }
  }

  if (max_cnt == 0)
  {
    most_sim_word1 = words[0];
    most_sim_word2 = words[1];
  }

  cout << most_sim_word1 << '\n' << most_sim_word2;

  return 0;
}