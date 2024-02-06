#include <bits/stdc++.h>

using namespace std;
int good = 1;

bool bfs(vector<string> room, int x, int y)
{ 
    queue<pair<int, int>> Q;
    int vis[5][5] = { 0 };
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    Q.push({x, y});
    vis[x][y] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        
        if (vis[cur.first][cur.second] == 3)
        {
            return true;
        }
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if (vis[nx][ny] != 0)
                continue;
            if (room[nx][ny] == 'X')
                continue;
            if (room[nx][ny] == 'P')
                return false;
         
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    
    return true;
}

void check_room(vector<string> room)
{
    for (int i = 0; i < room.size(); i++)
    {
        for (int j = 0; j < room[i].length(); j++)
        {
            if (room[i][j] == 'P')
            {
                if(!bfs(room, i, j))
                {
                    good = 0;
                    return;
                }
            }
        }
    }
    
    return;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int t = 0; t < places.size(); t++)
    {
        good = 1;
        check_room(places[t]);
        answer.push_back(good);
    }
    
    return answer;
}