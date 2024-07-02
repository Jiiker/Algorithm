#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0, right = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while(left <= right) {
        int l = limit;
        int cnt = 0;
        
        while(l >= people[right]) {
            if (cnt == 2)
                break;
            
            l -= people[right];
            right--;
            cnt++;
        }
        while(left <= right && l >= people[left]) {
            if (cnt == 2)
                break;
            
            l -= people[left];
            left++;
            cnt++;
        }
        
        answer++;
    }
        
    return answer;
}