#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    
    while (n > 0) {
        int cur_work = pq.top(); pq.pop();
        
        if (cur_work > 0) cur_work--;
        n--;
        pq.push(cur_work);
    }
    
    for (int i = 0; i < works.size(); i++) {
        int cur_work = pq.top(); pq.pop();
        answer += cur_work * cur_work;
    }
    
    return answer;
}