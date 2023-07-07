#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int k = 0, cnt = 0;;

    for (int i = 0; i < cards1.size(); i++)
    {
        while (k < goal.size())
        {
            if (goal[k].compare(cards1[i]) == 0)
            {
                k++;
                cnt++;
                break;
            }
            k++;
        }
        if (k == goal.size())
            break;
    }

    k = 0;
    for (int i = 0; i < cards2.size(); i++)
    {
        while (k < goal.size())
        {
            if (goal[k].compare(cards2[i]) == 0)
            {
                k++;
                cnt++;
                break;
            }
            k++;
        }
        if (k == goal.size())
            break;
    }

    if (cnt < goal.size())
        return "No";

    answer = "Yes";

    return answer;
}