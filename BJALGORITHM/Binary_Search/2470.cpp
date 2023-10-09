#include <bits/stdc++.h>

using namespace std;

vector<int> V;
int N = 0;
int result_CV = INT_MAX;
int result_opposite_num = 0;
int result_num = 0;

int binarysearch(int st, int en, int num);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int input = 0;
    cin >> input;
    V.push_back(input);
  }
  
  sort(V.begin(), V.end());

  for (int i = 0; i < N; i++)
  {
    int opposite_num = 0;

    if ((V[i] < 0 && i < N - 1) || (V[i] > 0 && i == 0))
      opposite_num = binarysearch(i + 1, N - 1, V[i]);
    else
      opposite_num = binarysearch(0, i - 1, V[i]);
    
    if (abs(V[i] + opposite_num) < result_CV)
    {
      result_CV = abs(V[i] + opposite_num);
      result_num = V[i];
      result_opposite_num = opposite_num;
    }
  }

  if (result_opposite_num > result_num)
    cout << result_num << " " << result_opposite_num;
  else
    cout << result_opposite_num << " " << result_num;

  return 0;
}

int binarysearch(int st, int en, int num)
{
  int min_CV = INT_MAX;
  int opposite_num = 0;

  while (st <= en)
  {  
    int mid = (st + en) / 2;

    if (num + V[mid] == 0)
    {
      return V[mid];
    }
    else if (num + V[mid] > 0)
    {
      if (num + V[mid] < min_CV)
      {
        min_CV = num + V[mid];
        opposite_num = V[mid];
      }
      en = mid - 1;
    }
    else
    {
      if (abs(num + V[mid]) < min_CV)
      {
        min_CV = abs(num + V[mid]);
        opposite_num = V[mid];
      }
      st = mid + 1;
    }
  }

  return opposite_num;
}