#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_x = 50, min_y = 50, max_x = 0, max_y = 0;

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i < min_x)
                    min_x = i;
                if (i > max_x)
                    max_x = i;
                if (j < min_y)
                    min_y = j;
                if (j > max_y)
                    max_y = j;
            }
        }
    }

    answer.push_back(min_x);
    answer.push_back(min_y);
    answer.push_back(max_x + 1);
    answer.push_back(max_y + 1);

    return answer;
}