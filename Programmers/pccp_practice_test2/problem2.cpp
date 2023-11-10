/*[PCCP 모의고사 #2] 2번 - 신입사원 교육*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < ability.size(); i++)
    {
        pq.push(ability[i]);
    }
    
    for (int t = 0; t < number; t++)
    {
        int min = 0;
        int snd_min = 0;
        
        min = pq.top(); pq.pop();
        snd_min = pq.top(); pq.pop();
        
        pq.push(min + snd_min);
        pq.push(min + snd_min);
    }
    
//     for (int t = 0; t < number; t++)
//     {
//         int min = 1000005;
//         int min_i = 0;
//         int snd_min = 1000005;
//         int snd_min_i = 0;
        
//         for (int i = 0; i < ability.size(); i++)
//         {
//             if (ability[i] <= min)
//             {
//                 min = ability[i];
//                 min_i = i;
//             }
//         }
//         ability[min_i] = 1000005;
        
//         for (int i = 0; i < ability.size(); i++)
//         {
//             if (ability[i] <= snd_min)
//             {
//                 snd_min = ability[i];
//                 snd_min_i = i;
//             }
//         }
        
//         ability[min_i] = min + snd_min;
//         ability[snd_min_i] = min + snd_min;
//     }
    
    while(!pq.empty())
    {
        int num = pq.top(); pq.pop();
        answer = answer + num;
    }
    
    return answer;
}