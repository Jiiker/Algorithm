#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str;
  stack<char> S1;
  stack<char> S2;

  int cmd_line;

  cin >> str;
  for (int i = 0; i < str.length(); i++)
    S1.push(str[i]);

  cin >> cmd_line;

  for (int i = 0; i < cmd_line; i++)
  {
    char cmd;
    cin >> cmd;

    if (cmd == 'L')
    {
      if (!S1.empty())
      {
        char c = S1.top(); S1.pop();
        S2.push(c);
      }
    }

    else if (cmd == 'D')
    {
      if (!S2.empty())
      {
        char c = S2.top(); S2.pop();
        S1.push(c);
      }
    }

    else if (cmd == 'B')
    {
      if (!S1.empty())
        S1.pop();
    }

    else if (cmd == 'P')
    {
      char c;
      cin >> c;
      S1.push(c);
    }
  }
  
  while (!S1.empty())
  {
    char c = S1.top(); S1.pop();
    S2.push(c);
  }

  while (!S2.empty())
  {
    cout << S2.top();
    S2.pop();
  }

  return 0;
}