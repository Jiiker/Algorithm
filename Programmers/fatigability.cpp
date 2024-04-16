#include <string>
#include <vector>

using namespace std;
int max_cnt = 0;

void back_tracking(int k, vector<vector<int>> dungeons, int check[8], int depth)
{
    int cnt = 0;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (check[i] == 1)
            continue;
        if (k < dungeons[i][0])
            continue;
        
        check[i] = 1;
        back_tracking(k - dungeons[i][1], dungeons, check, depth + 1);
        check[i] = 0;
    }
    
    for (int i = 0; i < 8; i++)
    {
        if (check[i] == 1)
            cnt++;
    }

    if (max_cnt < cnt)
        max_cnt = cnt;
    
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int check[8] = { 0 };
    
    back_tracking(k, dungeons, check, 0);
    
    answer = max_cnt;
    
    return answer;
}