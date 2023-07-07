#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) 
{
    int answer = 0;
    int start = 0, end = 0;
    sort(targets.begin(), targets.end());

    for(int i = 0; i < targets.size(); i++)
    {
        int cur_s = targets[i][0];
        int cur_e = targets[i][1];

        if (cur_s < end)
        {
            if (cur_e < end)
                end = cur_e;
            continue;
        }
        else
        {
            answer++;
            start = cur_s;
            end = cur_e;
        }
    }
    
    return answer;
}