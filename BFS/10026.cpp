#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, cnt = 0, cnt_CB = 0;
    char paint[105][105] = { 0 };
    int vis[105][105] = { 0 };
    int vis_CB[105][105] = { 0 };
    queue<pair<int, int> > Q;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> paint[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] == 0 && (paint[i][j] == 'R' || paint[i][j] == 'G' || paint[i][j] == 'B'))
            {
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;
            }

            while (!Q.empty())
            {
                int dx[4] = {1, 0, -1, 0};
                int dy[4] = {0, 1, 0, -1};
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (vis[nx][ny] == 1 || paint[i][j] != paint[nx][ny])
                        continue;
                    if (nx >= N || nx < 0 || ny >= N || ny < 0)
                        continue;
                    
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis_CB[i][j] == 0 && (paint[i][j] == 'R' || paint[i][j] == 'G' || paint[i][j] == 'B'))
            {
                Q.push({i, j});
                vis_CB[i][j] = 1;
                cnt_CB++;
            }

            while (!Q.empty())
            {
                int dx[4] = {1, 0, -1, 0};
                int dy[4] = {0, 1, 0, -1};
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (vis_CB[nx][ny] == 1)
                        continue;
                    if (paint[cur.first][cur.second] == 'R' && paint[nx][ny] == 'B')
                        continue;
                    if (paint[cur.first][cur.second] == 'G' && paint[nx][ny] == 'B')
                        continue;
                    if (paint[cur.first][cur.second] == 'B' && paint[nx][ny] != 'B')
                        continue;
                    if (nx >= N || nx < 0 || ny >= N || ny < 0)
                        continue;
                    
                    Q.push({nx, ny});
                    vis_CB[nx][ny] = 1;
                }
            }
        }
    }

    cout << cnt << ' ' << cnt_CB;

    return 0;
}