#include <bits/stdc++.h>

using namespace std;

int main() 
{
  string str;
  bool zero_flag = false;
  bool one_flag = false;
  vector<char> C;

  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '0')
    {
      zero_flag = !zero_flag;

      if (zero_flag == false)
        C.push_back(str[i]);
    }
    else if (str[i] == '1')
    {
      one_flag = !one_flag;

      if (one_flag == false)
        C.push_back(str[i]);
    }
  }

  sort(C.begin(), C.end());
  for (int i = 0; i < C.size(); i++)
  {
    cout << C[i];
  }

  return 0;
}