/*[PCCP 모의고사 #2] 3번 - 카페 확장*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k) {
    int answer = 0;
    int cur_time = 0;
    int cur_people = 0;
    int next_time = 0;
    int temp = 0;
    
    for (int i = 0; i < order.size(); i++)
    {
        if (cur_time <= k * i)
        {
            cur_people++;
            cur_time = k * i;
            temp = k * i;
        }
        next_time = cur_time + menu[order[i]];        

        while (temp + k < next_time && temp + k <= k *(order.size() - 1))
        {
            temp = temp + k;
            cur_people++;
        }

        if (cur_people > answer)
            answer = cur_people;
        
        cur_people--;
        cur_time = next_time;
    }
    
    return answer;
}