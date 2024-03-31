#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    vector<string> list;
    
    for (int i = 0; i < want.size(); i++)
    {
        m.insert({want[i], number[i]});
    }

    for (int i = 0; i < discount.size(); i++)
    {
        list.push_back(discount[i]);
        m[discount[i]]--;
        
        if (list.size() < 10)
            continue;
        
        int flag = 1;
        for (int j = 0; j < list.size(); j++)
        {
            if (m[list[j]] < 0)
                flag = 0;
        }
        
        if (flag)
            answer++;
        
        m[list.front()]++;
        list.erase(list.begin());
    }
    
    return answer;
}