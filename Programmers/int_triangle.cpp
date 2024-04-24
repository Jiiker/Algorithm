#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int sum[500][500] = { 0 };
    priority_queue<int> pq;
    
    sum[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int max_value = 0;
            
            if (j == 0)
                max_value = sum[i - 1][j];
            else if (j == i + 1)
                max_value = sum[i - 1][j - 1];
            else
                max_value = max(sum[i - 1][j], sum[i - 1][j - 1]);
            
            sum[i][j] = triangle[i][j] + max_value;
            
            if (i == triangle.size() - 1)
            {
                pq.push(sum[i][j]);
            }
        }
    }
    
    answer = pq.top();
    
    return answer;
}