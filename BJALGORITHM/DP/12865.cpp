#include <bits/stdc++.h>

using namespace std;

int main()
{
  int num, weight;
  int arr[100005] = { 0 };
  cin >> num >> weight;

  for (int i = 0; i < num; i++)
  {
    int w, v;
    cin >> w >> v;

    for (int j = weight; j >= w; j--)
    {
      if (arr[j-w] + v > arr[j])
        arr[j] = arr[j-w] + v;
    }
  }

  cout << arr[weight];

  return 0;
}