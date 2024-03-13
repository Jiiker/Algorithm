#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) {
    int answer;
    int LCM = 0;
    
    LCM = arr[0];
    
    for (int i = 1; i < arr.size(); i++)
    {
        LCM = lcm(LCM, arr[i]);
    }
    
    answer = LCM;
    
    return answer;
}