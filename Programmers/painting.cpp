#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int arr[100005] = { 0 };
    int num_wall = section.size();
    int cnt = 0;
    
    for (int i = 0; i < num_wall; i++)
    {
        arr[section[i]] = 1;
    }
    
    for (int i = 0; i < num_wall; i++)
    {
        if (arr[section[i]] == 0)
            continue;
        else
        {
            for (int j = 0; j < m; j++)
            {
                if (section[i] + j > 100000)
                    break;
                arr[section[i] + j] = 0;
            }
            cnt++;
        }
    }
    
    answer = cnt;
    
    return answer;
}