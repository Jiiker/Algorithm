#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0;
    

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int board[301][301];
        int vis[301][301] = { 0 };
        int I = 0, start_x = 0, start_y = 0;
        int end_x = 0, end_y = 0;
        queue<pair<int, int> > Q;
        cin >> I >> start_x >> start_y >> end_x >> end_y;

        Q.push({start_x, start_y});
        vis[start_x][start_y] = 1;
        board[start_x][start_y] = 0;
        while(!Q.empty())
        {
            int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2};
            int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1};
            pair<int, int> cur = Q.front();
            Q.pop();
            if (cur.first == end_x && cur.second == end_y)
            {
                cout << board[end_x][end_y] << '\n';
                break;
            }

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (vis[nx][ny] == 1)
                    continue;
                if (nx >= I || nx < 0 || ny >= I || ny < 0)
                    continue;
                
                Q.push({nx, ny});
                vis[nx][ny] = 1;
                board[nx][ny] = board[cur.first][cur.second] + 1;
                
            }
        }
    }

    return 0;
}