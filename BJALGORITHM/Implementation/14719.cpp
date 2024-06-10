#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> blocks;
  int H, W;
  int max_value = 0;
  int prev = 0;
  int answer = 0;

  cin >> H >> W;

  for (int i = 0; i < W; i++)
  {
    int height;
    cin >> height;

    blocks.push_back(height);
  }

  for (int i = 0; i < blocks.size(); i++)
  {
    if (blocks[i] > prev && max_value > prev)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (blocks[j] >= blocks[i])
          break;

        if (prev < blocks[j])
          prev = blocks[j];
        answer += (min(max_value, blocks[i]) - prev);
      }
    }

    prev = blocks[i];
    if (max_value < blocks[i])
      max_value = blocks[i];
  }

  cout << answer;

  return 0;
}