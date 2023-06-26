#include <bits/stdc++.h>
 
using namespace std;
 
int T = 0, N = 0;
int num_core = 0, length = 0, num_line = 0;
int four_cnt = 0;
int min_length = 150, max_line = 0;
int maxinos[13][13] = { 0 };
int dir_line[30];
vector<pair<int, int> > v;
 
void wiring(void)
{
    length = 0;
    num_line = 0;
    int dup_maxinos[13][13];
 
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
 
    copy(&maxinos[0][0], &maxinos[0][0] + (13 * 13), &dup_maxinos[0][0]);
     
    for (int i = 0; i < num_core; i++)
    {
        int nx = v[i].first;
        int ny = v[i].second;
        int dir = dir_line[i];
 
        if (dir == 5)
        {
            num_line++;
            continue;
        }
        if (dir == 4)
            continue;
        while (1)
        {
            nx = nx + dx[dir];
            ny = ny + dy[dir];
             
            if (dup_maxinos[nx][ny] == 'L')
                return;
 
            if (nx >= N || nx < 0 || ny >= N || ny < 0)
            {
                num_line++;
                nx = nx - dx[dir];
                ny = ny - dy[dir];
                while (!(nx == v[i].first && ny == v[i].second))
                {
                    dup_maxinos[nx][ny] = 'L';
                    length++;
                    nx = nx - dx[dir];
                    ny = ny - dy[dir];
                }
                break;
            }  
        }
    }
    return;
}

void choose_dir(int k)
{
    int x = v[k].first;
    int y = v[k].second;
 
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    if (k == num_core)
    {
        wiring();
 
        if (num_line > max_line)
        {
            max_line = num_line;
            min_length = length;
        }
        else if (num_line == max_line)
        {
            if (length < min_length)
                min_length = length;
        }
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        int nx = x;
        int ny = y;
        int flag = 0;

        if (x == 0 || x == N - 1 || y == 0 || y == N - 1)
            i = 5;
        dir_line[k] = i;
 
        if (i == 4)
            four_cnt++;
        if (four_cnt > num_core - max_line)
        {
            four_cnt--;
            continue;
        }

        if (i < 4)
        {   
            nx = nx + dx[i];
            ny = ny + dy[i];
            while (nx < N && nx >= 0 && ny < N && ny >= 0)
            {
                if (maxinos[nx][ny] == 1)
                {
                    flag = 1;
                    break;
                }
                nx = nx + dx[i];
                ny = ny + dy[i];  
            }
            if (flag == 1)
                continue;
        }

        choose_dir(k + 1);
         
        if (i == 4)
            four_cnt--;
    }
    return;
}
 
int main(int argc, char** argv)
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;
     
    cin >> T;
     
    for(test_case = 1; test_case <= T; ++test_case)
    {
        num_core = 0;
        min_length = 150;
        max_line = 0;
        length = 0; 
        num_line = 0;
        four_cnt = 0;
        cin >> N;
        v.clear();
 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> maxinos[i][j];
                if (maxinos[i][j] == 1)
                {
                    num_core++;
                    v.push_back({i, j});
                }
            }
        }
 
        choose_dir(0);
 
        cout << '#' << test_case << ' ' << min_length << '\n';
    }
    return 0;
}