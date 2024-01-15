#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testcase;
  cin >> testcase;

  for (int t = 0; t < testcase; t++)
  {
    string str;
    int num, cnt_min = INT_MAX, cnt_max = 0;
    cin >> str >> num;

    for (char c = 'a'; c <= 'z'; c++)
    {
      int c_cnt = 0, str_len = 0, node_len = 0;
      queue<int> nodes;
      for (int i = 0; i < str.length(); i++)
      {
        if (c_cnt == 0 && str[i] != c)
          continue;

        if (str[i] == c)
        {
          if (c_cnt == num)
          {
            int temp_node_len = nodes.front(); nodes.pop();
            str_len = str_len - temp_node_len;
            c_cnt--;
          }
          c_cnt++;

          if (!nodes.empty())
            nodes.back() = nodes.back() + node_len;
          str_len = str_len + node_len + 1;
          node_len = 0;
          nodes.push(1);
        }
        else
          node_len++;

        if (c_cnt == num)
        {
          if (str_len < cnt_min)
            cnt_min = str_len;
          if (str_len > cnt_max)
          {
            cnt_max = str_len;
            cout << "len: " << str_len << " // char: " << c << '\n';
          }
        }
      }
    }
    if (cnt_min == INT_MAX || cnt_max == 0)
      cout << -1 << '\n';
    else
      cout << cnt_min << ' ' << cnt_max << '\n';
  }

  return 0;
}