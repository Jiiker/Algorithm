#include <bits/stdc++.h>

using namespace std;
int path[17][17] = { 0 };
int sheeps = 0;
int wolves = 0;
int max_sheeps = 0;

void dfs(vector<int> info, int check[17])
{
    queue<int> Q;
    
    for (int i = 0; i < 18; i++)
    {
        if (check[i] == 1)
        {
            for (int j = 0; j < 18; j++)
            {
                if (path[i][j] == 1 && check[j] == 0)
                    Q.push(j);
            }
        }
    }
    
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        
        if (info[cur] == 1 && sheeps == wolves + 1)
            continue;
        
        if (info[cur] == 0)
            sheeps++;
        if (info[cur] == 1)
            wolves++;
        
        if (sheeps > max_sheeps)
            max_sheeps = sheeps;
        
        check[cur] = 1;
        dfs(info, check);
        
        if (info[cur] == 0)
            sheeps--;
        if (info[cur] == 1)
            wolves--;
        
        check[cur] = 0;
    }
    
    if (sheeps > max_sheeps)
        max_sheeps = sheeps;
    
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int check[17] = { 0 };
    
    for (int i = 0; i < edges.size(); i++)
    {
        path[edges[i][0]][edges[i][1]] = 1;
    }
    
    check[0] = 1;
    sheeps++;
    dfs(info, check);
    
    answer = max_sheeps;
    
    return answer;
}