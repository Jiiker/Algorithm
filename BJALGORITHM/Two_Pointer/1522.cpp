#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str, str_sum;
  int len;
  
  int a_cnt = 0, b_cnt = 0;
  int min_b_cnt = INT_MAX;
  int left = 0, right = 0;

  cin >> str;

  str_sum = str + str;
  len = str.length();

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'a')
      a_cnt++;
  }

  right = a_cnt;
  while (right <= 2*len)
  {
    b_cnt = 0;
    for (int i = left; i < right; i++)
    {
      if (str_sum[i] == 'b')
        b_cnt++;
    }

    if (b_cnt < min_b_cnt)
      min_b_cnt = b_cnt;

    left++;
    right++;
  }

  cout << min_b_cnt;

  return 0;
}