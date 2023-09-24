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
        int m, n, x, y, k, cnt = 0;
        int field[55][55] = { 0 };
        int vis[55][55] = { 0 };
        queue<pair<int, int> > Q;
        
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            field[y][x] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (field[j][k] == 1 && vis[j][k] == 0)
                {
                    Q.push({k, j});
                    vis[j][k] = 1;

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

                            if (field[ny][nx] == 0 || vis[ny][nx] == 1)
                                continue;
                            if (nx >= m || nx < 0 || ny >= n || ny < 0)
                                continue;
                            
                            Q.push({nx, ny});
                            vis[ny][nx] = 1;
                        }
                    }
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}