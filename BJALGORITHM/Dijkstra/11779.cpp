#include <bits/stdc++.h>

using namespace std;

int main()
{
  int numOfCity = 0, numOfBus = 0;
  int startCity = 0, endCity = 0;
  vector<pair<int, int>> path[1005]; // path[출발지] = {비용, 도착지}
  int minCost[1005] = { 0 };
  int preCity[1005] = { 0 };
  int cnt = 0;

  fill(minCost, minCost + 1001, INT_MAX);

  cin >> numOfCity >> numOfBus;

  for (int i = 0; i < numOfBus; i++)
  {
    int st, end, cost;

    cin >> st >> end >> cost;

    path[st].push_back({cost, end});
  }

  cin >> startCity >> endCity;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  pq.push({0, startCity});
  minCost[startCity] = 0;

  while(!pq.empty())
  {
    pair<int, int> curCity = pq.top(); pq.pop();

    if (minCost[curCity.second] != curCity.first)
      continue;

    for (int i = 0; i < path[curCity.second].size(); i++)
    {
      pair<int, int> nextCity = path[curCity.second][i];

      if (minCost[nextCity.second] <= minCost[curCity.second] + nextCity.first)
        continue;
      
      preCity[nextCity.second] = curCity.second;
      minCost[nextCity.second] = minCost[curCity.second] + nextCity.first;
      pq.push({minCost[nextCity.second], nextCity.second});
    }
  }

  cout << minCost[endCity] << '\n';

  stack<int> route;
  route.push(endCity);
  while (endCity != startCity)
  {
    route.push(preCity[endCity]);
    endCity = preCity[endCity]; 
  }

  cout << route.size() << '\n';
  while(!route.empty())
  {
    cout << route.top() << ' ';
    route.pop();
  }

  return 0;
}