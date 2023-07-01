#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, cnt_complex = 0, cnt = 0;
    char apart[30][30];
    int vis[30][30] = { 0 };
    int cnt_save[350] = { 0 };
    int cnt_i = 0;

    queue<pair<int, int> > Q;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> apart[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (apart[i][j] == '1' && vis[i][j] == 0)
            {
                cnt = 0;
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;

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

                        if (nx >= N || nx < 0 || ny >= N || ny < 0)
                            continue;
                        if (apart[nx][ny] != '1' || vis[nx][ny] != 0)
                            continue;
                        
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                        cnt++;
                    }
                }
                cnt_save[cnt_i++] = cnt;
                cnt_complex++;
            }
        }
    }

    cout << cnt_complex << '\n';
    sort(cnt_save, cnt_save + cnt_i);

    for (int i = 0; i < cnt_i; i++)
        cout << cnt_save[i] << '\n';

    return 0;
}