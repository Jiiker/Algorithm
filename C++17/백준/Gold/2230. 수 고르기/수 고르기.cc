#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  int right = 0;
  int left = 0;
  int min_dif = INT_MAX;
  vector<int> nums;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  while (left < N && right < N && left <= right) {
    int dif = nums[right] - nums[left];

    if (dif < M) {
      right++;
    } else if (dif > M) {
      if (dif < min_dif) {
        min_dif = dif;
      }
      left++;
    } else if (dif == M) {
      min_dif = dif;
      break;
    }
  }

  cout << min_dif;

  return 0;
}