#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;
    int sec1 = (3600 * h1) + (60 * m1) + (s1);
    int sec2 = (3600 * h2) + (60 * m2) + (s2);
    int alam = 0;
    
    for (int i = sec1; i <= sec2; i++)
    {
        int cur_hour = i % 43200;
        int cur_min = (i * 12) % 43200;
        int cur_sec = (i * 720) % 43200;
        
        
        if (i == sec2)
        {
            if (cur_hour == cur_sec)
                alam++;
            if (cur_min == cur_sec)
                alam++;
            if (cur_sec == cur_hour && cur_sec == cur_min)
                alam--;
            break;
        }
        
        int next_hour = cur_hour + 1;
        int next_min = cur_min + 12;
        int next_sec = cur_sec + 720;
        
        if (cur_sec <= cur_hour && next_sec > next_hour)
            alam++;
        if (cur_sec <= cur_min && next_sec > next_min)
            alam++;
        if (cur_sec == cur_hour && cur_sec == cur_min)
            alam--;
    }
    
    answer = alam;
    
    return answer;
}