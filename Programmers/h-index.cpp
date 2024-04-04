#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for (int h = 1; h <= 1000; h++)
    {
        int cnt = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] - h >= 0)
                cnt++;
        }
        answer = max(answer, min(h, cnt));
    }
    
    return answer;
}