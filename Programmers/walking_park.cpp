#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int sx = 0, sy = 0;
    int H = park.size();
    int W = park[0].size();
    
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (park[i][j] == 'S')
            {
                sx = i;
                sy = j;
                break;
            }
        }
        if (park[sx][sy] == 'S')
            break;
    }
    
    for (int i = 0; i < routes.size(); i++)
    {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = { 0, 0, -1, 1};
        int save_x, save_y;
        int dir;
        char c;
        int go;
        
        c = routes[i][0];
        go = routes[i][2] - '0';
        
        if (c == 'N')
            dir = 0;
        else if (c == 'S')
            dir = 1;
        else if (c == 'W')
            dir = 2;
        else if (c == 'E')
            dir = 3;
        
        save_x = sx;
        save_y = sy;
        for (int j = 0; j < go; j++)
        {
            int nx = sx + dx[dir];
            int ny = sy + dy[dir];
            
            if (nx >= H || nx < 0 || ny >= W || ny < 0)
            {
                sx = save_x;
                sy = save_y;
                break;
            }
            if (park[nx][ny] == 'X')
            {
                sx = save_x;
                sy = save_y;
                break;
            }
            
            sx = nx;
            sy = ny;
        }
    }
    
    answer.push_back(sx);
    answer.push_back(sy);
    
    return answer;
}