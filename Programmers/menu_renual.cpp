#include <bits/stdc++.h>

using namespace std;
vector<string> answer;
vector<string> temp;
int cnt_max = 0;

bool is_contained(string str1, string str2)
{
  for (int i = 0; i < str2.length(); i++)
  {
    for (int j = 0; j < str1.length(); j++)
    {
      if (str2[i] == str1[j])
        break;
      
      if (j == str1.length() - 1)
        return false;
    }
  }
  
  return true;
}

void make_alpha_comb(vector<string> orders, vector<int> check, int k, int C, int prev)
{
  if (k == C)
  {
    string str = "";
    int cnt = 0;
    for (int i = 0; i < check.size(); i++)
    {
      char c = check[i] + 'A';
      str = str + c;
    }
    
    for (int i = 0; i < orders.size(); i++)
    {
      if (orders[i].length() < str.length())
        continue;
      if (is_contained(orders[i], str))
        cnt++;
    }
    
    if (cnt < 2)
      return;
    
    if (cnt > cnt_max)
    {
      cnt_max = cnt;
      temp.clear();
      temp.push_back(str);
    }
    else if (cnt == cnt_max)
    {
      temp.push_back(str);
    }
    
    return;
  }
  
  for (int i = prev + 1; i < 26; i++)
  {
    check.push_back(i);
    make_alpha_comb(orders, check, k+1, C, i);
    check.pop_back();
  }
  
  return;
}

vector<string> solution(vector<string> orders, vector<int> course) { 
  vector<int> check;
  
  for (int i = 0; i < course.size(); i++)
  {
    cnt_max = 0;
    temp.clear();
    make_alpha_comb(orders, check, 0, course[i], -1);
    
    for (int t = 0; t < temp.size(); t++)
      answer.push_back(temp[t]);
  }
  
  sort(answer.begin(), answer.end());
  
  return answer;
}
