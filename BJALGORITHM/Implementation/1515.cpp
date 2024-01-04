#include <bits/stdc++.h>

using namespace std;

int main()
{
  string SJ_num;
  vector<int> V;
  bool finish = false;
  int result = 0;
  int idx = 1;
  
  cin >> SJ_num;

  for (int i = 0; i < SJ_num.length(); i++)
  {
    V.push_back(SJ_num[i]);
  }

  while(1)
  {
    string num = to_string(idx);
  
    for (int j = 0; j < num.length(); j++)
    {
      if (V.front() == num[j])
        V.erase(V.begin());
      
      if (V.empty())
      {
        finish = true;
        result = idx;
        break;
      }
    }
    if (finish)
    {
      break;
    }
    idx++;
  }

  cout << result;

  return 0;
}

