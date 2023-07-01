#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    char miro[1005][1005];
    int vis[1005][1005];
    queue<pair<int, int> > Q;
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> miro[i][j];
            if (miro[i][j] == 'J')
            {
                Q.push({ i, j });
                vis[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (miro[i][j] == 'F')
            {
                Q.push({ i, j });
                vis[i][j] = 1;
            }
        }
    }

    while (!Q.empty())
    {
        int dx[4] = { 1, 0, -1, 0 };
        int dy[4] = { 0, 1, 0, -1 };
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (miro[cur.first][cur.second] == 'J' && (nx >= R || nx < 0 || ny >= C || ny < 0))
            {
                cout << vis[cur.first][cur.second];
                return 0;
            }
            if (miro[cur.first][cur.second] == 'J' && miro[nx][ny] == 'J')
                continue;
            if (miro[nx][ny] == '#' || miro[nx][ny] == 'F')
                continue;
            if (nx >= R || nx < 0 || ny >= C || ny < 0)
                continue;

            miro[nx][ny] = miro[cur.first][cur.second];
            Q.push({ nx, ny });
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}