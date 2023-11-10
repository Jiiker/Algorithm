/*[PCCP 모의고사 #2] 1번 - 실습용 로봇*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string command) {
    vector<int> answer;
    int x = 0, y = 0;
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    int dir = 0;
    
    for (int i = 0; i < command.length(); i++)
    {
        if (command[i] == 'R')
        {
            if (dir == 3)
            {
                dir = 0;
                continue;
            }
            dir++;
        }
        else if (command[i] == 'L')
        {
            if (dir == 0)
            {
                dir = 3;
                continue;
            }
            dir--;
        }
        else if (command[i] == 'G')
        {
            x = x + dx[dir];
            y = y + dy[dir];
        }
        else if (command[i] == 'B')
        {
            x = x - dx[dir];
            y = y - dy[dir];
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}