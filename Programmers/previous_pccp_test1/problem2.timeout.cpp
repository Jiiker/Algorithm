#include <bits/stdc++.h>

using namespace std;
int arr[150000] = { 0 };
int land_num = 5;

vector<vector<int>> DFS(vector<vector<int>> land, int n, int m)
{
    stack<pair<int, int> > S;
    int vis[505][505] = { 0 };
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 1 && vis[i][j] == 0)
            {
                int area = 1;
                S.push({i, j});
                vis[i][j] = 1; 
                land[i][j] = land_num;
                
                while(!S.empty())
                {
                    pair<int, int> cur = S.top(); S.pop();
                    int dx[4] = { 1, 0, -1, 0 };
                    int dy[4] = { 0, 1, 0, -1 };
                    
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (land[nx][ny] == 0 || vis[nx][ny] == 1)
                            continue;
                        
                        area++;
                        S.push({nx, ny});
                        vis[nx][ny] = 1;
                        land[nx][ny] = land_num;
                    }
                }
                
                arr[land_num] = area;
                land_num++;
            }
        }
    }
    
    return land;
}

int drilling(vector<vector<int>> land, int n, int m)
{
    int sum = 0;
    int max_sum = 0;
    
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        int check_lump[150000] = { 0 };
        for (int j = 0; j < n; j++)
        {
            if (check_lump[land[j][i]] == 0 && land[j][i] != 0)
            {
                check_lump[land[j][i]] = 1;
                sum = sum + arr[land[j][i]];
            }
        }
        if (sum > max_sum)
            max_sum = sum;
    }
    
    return max_sum;
}


int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    
    land = DFS(land, n, m);

    answer = drilling(land, n, m);
    
    return answer;
}