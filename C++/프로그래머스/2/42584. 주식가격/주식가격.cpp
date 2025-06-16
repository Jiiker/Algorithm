#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> S; // {value, index} 형태로 저장.
    
    for (int i = 0; i < prices.size(); i++) {
        answer.push_back(0);
    }
    
    for (int i = 0; i < prices.size(); i++) {
        int cur_price = prices[i];
        
        while (S.size() && cur_price < S.top().first) {
            int prev_index = S.top().second;
            S.pop();
            
            answer[prev_index] = i - prev_index;
        }
        
        S.push({cur_price, i});
    }
    
    for (int i = 0; i < prices.size() - 1; i++) {
        if (answer[i] == 0) {
            answer[i] = prices.size() - 1 - i;
        }
    }
    
    return answer;
}