#include <bits/stdc++.h>

using namespace std;

int main()
{
  string num;
  int arr[100000];
  int flag = 0, sum = 0;
  cin >> num;

  for (int i = 0; i < num.length(); i++)
  {
    arr[i] = num[i] - '0';
    if (num[i] == '0')
      flag = 1;
    else
      sum = sum + (num[i] - '0');
  }

  if (flag == 0 || (sum % 3) != 0)
    cout << -1;
  else {
    sort(arr, arr + num.length(), greater<>());
    for (int i = 0; i < num.length(); i++)
      cout << arr[i];
  }

  return 0;
}