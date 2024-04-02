#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++)
    {
        int Q, R;
        Q = i / n;
        R = i % n;
        
        answer.push_back(max(Q, R) + 1);
    }
    
    return answer;
}