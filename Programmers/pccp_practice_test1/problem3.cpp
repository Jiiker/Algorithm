/* [PCCP 모의고사 #1] 3번 - 유전법칙 */

#include <string>
#include <vector>

using namespace std;

string search_parent(int o, int g)
{
    if (g == 1)
        return "Rr";
    int group = ((o - 1) / 4) + 1;
    int brother = o % 4;
    string p_cha = search_parent(group, g - 1);
    
    if (p_cha == "RR")
        return "RR";
    else if (p_cha == "rr")
        return "rr";
    else if (p_cha == "Rr")
    {
        if (brother == 1)
            return "RR";
        if (brother == 2)
            return "Rr";
        if (brother == 3)
            return "Rr";
        if (brother == 0)
            return "rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for (int i = 0; i < queries.size(); i++)
    {
        int generation = queries[i][0];
        int order = queries[i][1];
        
        answer.push_back(search_parent(order, generation));
    }
    
    
    return answer;
}