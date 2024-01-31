#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> kind;
    set<string> check_kind;
    map<string, int> count_kind;
    int min = INT_MAX;
    int x = 0, y = 0;
    int save_x = 0, save_y = 0;
    
    for (int i = 0; i < gems.size(); i++)
        kind.push_back(gems[i]);
    
    sort(kind.begin(), kind.end());
    kind.erase(unique(kind.begin(), kind.end()), kind.end());
    
    while (x <= y && y <= gems.size())
    {
        if (check_kind.size() < kind.size())
        {
            if (y == gems.size())
                break;
            y++;
            check_kind.insert(gems[y-1]);
            count_kind[gems[y-1]]++;
        }
        else
        {
            x++;
            count_kind[gems[x-1]]--;
            if (count_kind[gems[x-1]] == 0)
                check_kind.erase(gems[x-1]);
        }
        
        if (check_kind.size() == kind.size())
        {
            if (y - x < min)
            {
                min = y - x;
                save_x = x + 1;
                save_y = y;
            }
        }    
    }
    
    answer.push_back(save_x);
    answer.push_back(save_y);
    
    return answer;
}