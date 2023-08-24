#include <bits/stdc++.h>

using namespace std;

int main()
{
  string arr;
  stack<int> S;
  int result = 0;
  int flag = 0;

  cin >> arr;

  for (int i = 0; i < arr.length(); i++)
  {
    if (arr[i] == '(')
    {
      int num = 0;
      if (!S.empty())
        num = S.top();
      S.push(num + 1);
      flag = 1;
    }

    else
    {
      if (flag == 1)
      {
        int num = S.top(); S.pop();
        result = result + (num - 1);
        flag = 0;
      }
      else
      {
        result = result + 1;
        S.pop();
      }
    }
  }

  cout << result;

  return 0;
}