#include <bits/stdc++.h>

using namespace std;

void calculate(char arr[15], int N)
{
  char prev = '\0';
  int num = 0;
  int result = 0;


  for (int i = 0; i < (2*N) - 1; i++)
  {
    if (arr[i] >= '0' && arr[i] <= '9')
    {
      num = (num * 10) + (arr[i] - '0');
    }
    

    if ((prev == '+' && (arr[i] == '+' || arr[i] == '-')) || (prev == '\0' && (arr[i] == '+' || arr[i] == '-')))
    {
      result = result + num;
      num = 0;
    }
    if ((prev == '-' && (arr[i] == '+' || arr[i] == '-')))
    {
      result = result - num;
      num = 0;
    }

    if (arr[i] == '+' || arr[i] == '-')
    {
      prev = arr[i];
    }
  }

  if (prev == '+' || prev == '\0')
    result = result + num;
  else if (prev == '-')
    result = result - num;

  if (result == 0)
  {
    for (int i = 0; i < (2*N) - 1; i++)
    {
      cout << arr[i];
    }
    cout << '\n';
  }

  return;
}

void make_exp(char arr[15], int N, int k)
{
  if (k == N - 1)
  {
    calculate(arr, N);
    return;
  }

  for (int i = 0; i < 3; i++)
  {
    char c;
    if (i == 0)
      c = ' ';
    else if (i == 1)
      c = '+';
    else
      c = '-';

    arr[(2*k) + 1] = c;
    make_exp(arr, N, k + 1);
  }

  return;
}

int main()
{
  int testcase = 0;
  cin >> testcase;

  for (int t = 0; t < testcase; t++)
  {
    char arr[15] = { '\0' };
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
      arr[2*i] = i + 1 + '0';
    }

    make_exp(arr, N, 0);
    cout << '\n';
  }

  return 0;
}