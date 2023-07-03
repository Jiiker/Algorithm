#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum = 0;
    
    for (int i = 0; i < photo.size(); i++)
    {
        for (int j = 0; j < photo[i].size(); j++)
        {
            for (int k = 0; k < name.size(); k++)
            {
                if (photo[i][j].compare(name[k]) == 0)
                {
                    sum = sum + yearning[k];
                }
            }
        }
        
        answer.push_back(sum);
        sum = 0;
    }
    
    return answer;
}