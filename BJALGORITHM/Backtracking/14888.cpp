#include <bits/stdc++.h>

using namespace std;
int max_value = INT_MIN;
int min_value = INT_MAX;

void calculate_eq(vector<int> number, vector<int> selected_oper)
{
  int prev = 0;

  for (int i = 0; i < number.size(); i++)
  {
    if (i == 0)
    {
      prev = prev + number[i];
      continue;
    }

    if (selected_oper[i - 1] == 0)
      prev = prev + number[i];
    else if (selected_oper[i - 1] == 1)
      prev = prev - number[i];
    else if (selected_oper[i - 1] == 2)
      prev = prev * number[i];
    else
      prev = prev / number[i];
  }

  if (prev > max_value)
    max_value = prev;
  if (prev < min_value)
    min_value = prev;

  return;
}

void choose_oper(int N, vector<int> number, int oper_left[4], vector<int> selected_oper)
{
  if (selected_oper.size() == N - 1)
  {
    calculate_eq(number, selected_oper);
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    if (oper_left[i] == 0)
      continue;
    
    oper_left[i]--;
    selected_oper.push_back(i);
    choose_oper(N, number, oper_left, selected_oper);
    selected_oper.pop_back();
    oper_left[i]++;
  }

  return;
}

int main()
{
  int N = 0;
  vector<int> number;
  vector<int> selected_oper;
  int oper[4] = { 0 }; // 덧셈(+), 뺄셈(-), 곱셈(*), 나눗셈(/)

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int temp;
    cin >> temp;

    number.push_back(temp);
  }

  for (int i = 0; i < 4; i++)
  {
    cin >> oper[i];
  }

  choose_oper(N, number, oper, selected_oper);

  cout << max_value << '\n' << min_value;

  return 0;
}