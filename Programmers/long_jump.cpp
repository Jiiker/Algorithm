#include <bits/stdc++.h>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long DP[2001] = { 0 };

    DP[1] = 1;
    DP[2] = 2;
    
    for (int i = 3; i <= n; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
    }
    
    answer = DP[n];
    
    return answer;
}