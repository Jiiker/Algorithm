/*[PCCP 모의고사 #2] 4번 - 보물 지도*/

#include <bits/stdc++.h>

using namespace std;
int map_arr[1005][1005] = { 0 };
int dx[8] = {1, 0, -1, 0, 2, 0, -2, 0};
int dy[8] = {0, 1, 0, -1, 0, 2, 0, -2};
int min_count = 5000;

void DFS(int count[][1005], int start_x, int start_y, int n, int m, int flag)
{
    if (start_x == n && start_y == m)
    {
        if (count[start_x][start_y] < min_count)
            min_count = count[start_x][start_y];
        return;
    }
    
    int kind_dir = 8;
    if (flag == 1)
        kind_dir = 4;
    
    for (int dir = 0; dir < kind_dir; dir++)
    {
        int nx = start_x + dx[dir];
        int ny = start_y + dy[dir];
        
        if (nx <= 0 || ny <= 0 || nx > n || ny > m)
            continue;
        if (map_arr[nx][ny] == -1)
            continue;
        if (count[nx][ny] != 0 || (nx == 1 && ny == 1))
            continue;
        if (dir >= 4)
            flag = 1;
        
        count[nx][ny] = count[start_x][start_y] + 1;
        DFS(count, nx, ny, n, m, flag);
        count[nx][ny] = 0;
    }
    
    return;
}

int solution(int n, int m, vector<vector<int>> hole) {
    int answer = 0;
    int count_arr[1005][1005] = { 0 };
    
    for (int i = 0; i < hole.size(); i++)
    {
        map_arr[hole[i][0]][hole[i][1]] = -1;   
    }
    map_arr[n][m] = 7777;
    
    DFS(count_arr, 1, 1, n, m, 0);
    answer = min_count;
    
    if (min_count == 5000)
        answer = -1;
    
    return answer;
}