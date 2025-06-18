#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_weight = 0;
    int time = 0;
    queue<pair<int, int>> Q; // {무게, 진입시간} 로 저장.
    
    while (truck_weights.size() > 0 || !Q.empty()) {
        while (!Q.empty() && time - Q.front().second == bridge_length) {            
            cur_weight -= Q.front().first;
            Q.pop();
        }
        
        if (truck_weights.size() > 0 && weight - cur_weight >= truck_weights[0]) {
            int cur_truck = truck_weights[0];
            truck_weights.erase(truck_weights.begin());
            
            Q.push({cur_truck, time});
            cur_weight += cur_truck;
        } 
        
        time++;
    }
    
    answer = time;
    
    return answer;
}