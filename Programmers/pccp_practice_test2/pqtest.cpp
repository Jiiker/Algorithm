#include <bits/stdc++.h>

using namespace std;

int main() {
  priority_queue<pair<int, int>, vector<pair<int, int>>> pq1;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
  priority_queue<vector<int>, vector<vector<int>>> pq3;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq4;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int num1, num2;
      vector<int> temp;
      num1 = i;
      num2 = j;
      temp.push_back(i);
      temp.push_back(j);

      pq1.push({i, j});
      pq2.push({i, j});
      pq3.push(temp);
      pq4.push(temp);
    }
  }

  cout << "******|| " << "pq1" << " ||*******" << '\n';
  while(!pq1.empty())
  {
    cout << pq1.top().first << ' ' << pq1.top().second << '\n';
    pq1.pop();
  }

  cout << "******|| " << "pq2" << " ||*******" << '\n';
  while(!pq2.empty())
  {
    cout << pq2.top().first << ' ' << pq2.top().second << '\n';
    pq2.pop();
  }

  cout << "******|| " << "pq3" << " ||*******" << '\n';
  while(!pq3.empty())
  {
    cout << pq3.top()[0] << ' ' << pq3.top()[1] << '\n';
    pq3.pop();
  }

  cout << "******|| " << "pq4" << " ||*******" << '\n';
  while(!pq4.empty())
  {
    cout << pq4.top()[0] << ' ' << pq4.top()[1] << '\n';
    pq4.pop();
  }

  return 0;
}