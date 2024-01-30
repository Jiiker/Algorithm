#include <bits/stdc++.h>

using namespace std;
int answer = 0;
vector<int> choose;
int flag = 0;

bool str_comp(string str_comp, string str_ban)
{
  if (str_comp.length() != str_ban.length())
    return false;
  
  for (int i = 0; i < str_comp.length(); i++)
  {
    if (str_ban[i] == '*')
      continue;
    if (str_comp[i] == str_ban[i])
      continue;
    
    return false;
  }
  
  cout << str_comp << ' ' << str_ban;
  return true;
}

void compare_id(vector<string> user_id, vector<string> banned_id, vector<int> choose, int check_ban[8], int k)
{
  int n = banned_id.size();
  if (flag == 1)
    return;
  
  if (k == n)
  {
    flag = 1;
    answer++;
    return;
  }
    
  for (int i = 0; i < n; i++)
  {
    if (check_ban[i] == 1)
      continue;

    if (str_comp(user_id[choose[k]], banned_id[i]))
    {
      check_ban[i] = 1;
      compare_id(user_id, banned_id, choose, check_ban, k+1);
      check_ban[i] = 0;
    }
  }
  
  return;
}

void choose_id(vector<string> user_id, vector<string> banned_id, int k, int prev)
{
  if (k == banned_id.size())
  {
    flag = 0;
    int arr[8] = { 0 };
    
    compare_id(user_id, banned_id, choose, arr, 0);
    
    return;
  }
  for (int i = prev + 1; i < user_id.size(); i++)
  {
    choose.push_back(i);
    choose_id(user_id, banned_id, k + 1, i);
    choose.pop_back();
  }
  
  return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
  choose_id(user_id, banned_id, 0, -1);
  
  return answer;
}