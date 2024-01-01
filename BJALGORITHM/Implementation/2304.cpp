#include <bits/stdc++.h>

using namespace std;

int main() 
{
  int N = 0;
  int max_h = 0;
  int idx_left = 0, idx_right = 0;
  int prev_value = 0;
  int prev_idx = 0;
  int sum = 0;
  vector<pair<int, int>> V;

  cin >> N;
  idx_right = N - 1;

  for (int i = 0; i < N; i++)
  {
    int L = 0, H = 0;
    cin >> L >> H;

    V.push_back({L, H});

    if (H > max_h)
      max_h = H;
  }

  sort(V.begin(), V.end());

  while (V[idx_left].second <= max_h)
  {
    if (V[idx_left].second > prev_value)
    {
      sum = sum + (prev_value * (V[idx_left].first - V[prev_idx].first));
      prev_value = V[idx_left].second;
      prev_idx = idx_left;
    }
    if (V[idx_left].second == max_h)
    {
      break;
    }
    
    idx_left++;
  }

  prev_idx = idx_right;
  prev_value = 0;
  while (V[idx_right].second <= max_h)
  {
    if (V[idx_right].second > prev_value)
    {
      sum = sum + (prev_value * (V[prev_idx].first - V[idx_right].first));
      prev_value = V[idx_right].second;
      prev_idx = idx_right;
    }
    if (V[idx_right].second == max_h)
    {
      break;
    }
    
    idx_right--;
  }

  sum = sum + (max_h * (V[idx_right].first - V[idx_left].first + 1));

  cout << sum;

  return 0;
}