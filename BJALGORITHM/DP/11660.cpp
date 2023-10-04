#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int size, testcase;
  int arr[1025][1025] = { 0 };

  cin >> size >> testcase;

  for (int i = 1; i <= size; i++)
  {
    for (int j = 1; j <= size; j++)
    {
      int num = 0;
      cin >> num;
      arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + num;
    }
  }

  for (int i = 0; i < testcase; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1] << '\n';
  }

  return 0;
}