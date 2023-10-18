#include <bits/stdc++.h>

using namespace std;

int str_check(string s)
{
  if (s.length() % 2 == 1)
    return 0;

  stack<int> flags;
  for (int i = 0; i < s.length(); i++)
  {
    if (flags.empty() && (s[i] == ']'|| s[i] ==')'))
      return 0;

    int cur_flag = 0;
    int prev_flag = 0;
    char c = s[i];
    if (c == '(')
      cur_flag = 1;
    else if (c == '[')
      cur_flag = 2;
    
    if (flags.empty())
    {
      flags.push(cur_flag);
      continue;
    }
    
    prev_flag = flags.top();

    if (prev_flag == 1 && c == ']')
      return 0;
    if (prev_flag == 2 && c == ')')
      return 0;

    if (c == ']' || c == ')')
    {
      flags.pop();
      continue;
    }
    
    flags.push(cur_flag);
  }

  return 1;
}

int calculater(string s)
{
  int result = 0;
  int multiple = 1;

  for (int i = 0; i < s.length(); i++)
  {
    if (i >= 1 && (s[i-1] == ']' || s[i-1] == ')') && (s[i] == ']' || s[i] == ')'))
    {
      if (s[i] == ')')
        multiple /= 2;
      else
        multiple /= 3;
      continue;
    }
    if (s[i] == '(')
      multiple *= 2;
      
    else if (s[i] == '[')
      multiple *= 3;
      
    else if (s[i] == ')' || ']')
    {
      result = result + multiple;
      if (s[i] == ')')
        multiple /= 2;
      else
        multiple /= 3;
    }
  }

  return result;
}

int main() {
  string str;
  cin >> str;
  
  if (!str_check(str))
  {
    cout << 0;
    return 0;
  }

  cout << calculater(str);

  return 0;
}