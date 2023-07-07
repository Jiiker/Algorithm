#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    
    for (int i = 0; i < targets.size(); i++)
    {
        int sum = 0;
        int flag = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            int min_cnt = 105;
            for (int key_num = 0; key_num < keymap.size(); key_num++)
            {
                int cnt = 0;
                for (int click = 0; click < keymap[key_num].size(); click++)
                {
                    cnt++;
                    if (keymap[key_num][click] == targets[i][j])
                    {
                        if (cnt < min_cnt)
                        {
                            min_cnt = cnt;
                            break;
                        }
                    }
                }
            }
            if (min_cnt == 105)
            {
                answer.push_back(-1);
                flag = 1;
                break;
            }
            sum = sum + min_cnt;
        }
        if (flag == 1)
            continue;
        answer.push_back(sum);
    }
    
    
    return answer;
}