#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<string> maps) 
{
    int answer = 0;
    int vis[100][100] = { 0 };
    queue<pair<int, int> > Q;
    int flag = 0;
    int ex = 0, ey = 0;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
            if (maps[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }

    while(!Q.empty())
    {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx >= maps.size() || nx < 0 || ny >= maps[0].size() || ny < 0)
                continue;
            if (vis[nx][ny] != 0 || maps[nx][ny] == 'X')
                continue;
            if (maps[nx][ny] == 'L')
            {
                int save_cnt = vis[cur.first][cur.second];
                flag = 1;
                while(!Q.empty())
                    Q.pop();
                for (int i = 0; i < maps.size(); i++)
                {
                    for (int j = 0; j < maps[0].size(); j++)
                    {
                        vis[i][j] = 0;
                    }
                }
                Q.push({nx, ny});
                vis[nx][ny] = save_cnt + 1;
                break;                     
            }
            if (nx == ex && ny == ey && flag == 1)
            {
                answer = vis[cur.first][cur.second];
                return answer;
            }

            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    
    return -1;
}

int main()
{
    vector<string> maps;

    int row = 0;

    cin >> row;

    for (int i = 0; i < row; i++)
    {
        string str;
        cin >> str;
        maps.push_back(str);   
    }

    cout << solution(maps);

    return 0;
}