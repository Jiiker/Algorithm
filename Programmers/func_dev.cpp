#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> queue;
    int cnt = 0;
    int max = 0;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        queue.push_back((100 - progresses[i] + (speeds[i] - 1)) / speeds[i]);
    }
    
    queue.push_back(INT_MAX);
    for (int i = 0; i < queue.size(); i++)
    {
        if (i == 0)
        {
            max = queue[i];
            cnt++;
            continue;
        }
        
        if (max < queue[i])
        {
            answer.push_back(cnt);
            max = queue[i];
            cnt = 1;
        }
        else
            cnt++;
    }
    
    return answer;
}