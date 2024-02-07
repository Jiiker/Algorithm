#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    int dp[100000] = { 0 };
    
    if (tops[0] == 1)
        dp[0] = 4;
    else
        dp[0] = 3;
    
    if (tops[1] == 1)
        dp[1] = (dp[0] * 4) - 1;
    else
        dp[1] = (dp[0] * 3) - 1;
    
    for (int i = 2; i < n; i++)
    {
        if (tops[i] == 1)
        {
            dp[i] = ((dp[i-1] * 4) - dp[i-2]) % 10007;
            if (dp[i] < 0)
                dp[i] = dp[i] + 10007;
        }
            
        else
        {
            dp[i] = ((dp[i-1] * 3) - dp[i-2]) % 10007;
            if (dp[i] < 0)
                dp[i] = dp[i] + 10007;
        }    
    }
    
    answer = dp[n - 1];

    return answer;
}