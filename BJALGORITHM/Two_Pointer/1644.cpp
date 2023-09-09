#include <bits/stdc++.h>
using namespace std;

int prime[4000001] = { 0 };

void isPrime()
{
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i <= 2000; i++)
  {
    if (prime[i] == 1)
      continue;
    for (int j = 2; i * j <= 4000000; j++)
    {
      prime[i * j] = 1;
    }
  }

  return;
}

int search_next_prime(int n) 
{
  int num;
  num = n;

  if (n < 2)
    return 2;

  while (1) 
  {
    num++;
    if (prime[num] == 0)
      return num;
  }
}

int main()
{
  queue<int> Q;
  int num = 0, cnt = 0, sum = 0;
  cin >> num;

  isPrime();

  for (int i = 2; i <= num; i)
  {
    if (sum < num)
    {
      sum = sum + i;
      Q.push(i);
    }
    while (sum > num)
    {
      sum = sum - Q.front();
      Q.pop();
    }
    if (sum == num)
    {
      cnt++;
      sum = sum - Q.front();
      Q.pop();
    }

    i = search_next_prime(i);
  }

  cout << cnt;

  return 0;
}