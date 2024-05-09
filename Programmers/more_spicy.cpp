#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int mix_cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while (1)
    {
        int fst_food = 0, snd_food = 0, mixed_food = 0;
        
        
        if (pq.top() >= K)
            break;
        if (pq.size() <= 1)
            return -1;
        
        mix_cnt++;
        fst_food = pq.top(); pq.pop();
        snd_food = pq.top(); pq.pop();
        
        mixed_food = fst_food + (2*snd_food);
        
        pq.push(mixed_food);
    }
    
    answer = mix_cnt;
    
    return answer;
}