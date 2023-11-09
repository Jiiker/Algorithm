/* [PCCP 모의고사 #1] 2번 - 체육대회 */
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void choose_player(vector<vector<int>> ability, int check_student[10], int cnt, int sum)
{
    int students = ability.size();
    int sports = ability[0].size();
    
    if (cnt == sports)
    {
        if (sum > answer)
            answer = sum;
        return;
    }

    for (int i = 0; i < students; i++)
    {
        if (check_student[i] == 1)
            continue;
        check_student[i] = 1;
        choose_player(ability, check_student, cnt + 1, sum + ability[i][cnt]);
        check_student[i] = 0;
    }
    
    return;
}

int solution(vector<vector<int>> ability) {
    int check_student[10] = { 0 };
    
    choose_player(ability, check_student, 0, 0);
    
    return answer;
}