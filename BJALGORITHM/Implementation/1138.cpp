#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N = 0;
  int arr[10] = { 0 };
  int line[10] = { 0 };

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++)
  {
    int cnt = 0;
    for (int j = 0; j < N; j++)
    {
      if (cnt == arr[i] && line[j] == 0)
      {
        line[j] = i+1;
        break; 
      }
      if (line[j] == 0)
        cnt++;
    }
  }

  for (int i = 0; i < N; i++)
  {
    cout << line[i] << ' ';
  }

  return 0;
}