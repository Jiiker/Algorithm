#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }

    
    while (!pq.empty())
    {
        if (q.front().first < pq.top())
        {
            pair<int, int> temp = q.front(); q.pop();
            q.push(temp);
            continue;
        }
        
        answer++;
        if (q.front().second == location)
            break;
        
        q.pop();
        pq.pop();
    }
    
    return answer;
}