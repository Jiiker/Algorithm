#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10][10];
int CCTV[10];
pair<int, int> loc_cctv[10];
int NUM_CCTV = 0;
int cnt = 0;
int min_cnt = 100;

void backtracking(int k)
{
    int dx[4] = { 1, 0, -1, 0};
    int dy[4] = { 0, 1, 0, -1};

    if (k == NUM_CCTV)
    {
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 0)
                    cnt++;
            }
        }

        if (min_cnt > cnt)
            min_cnt = cnt;
        return;
    }

    if (CCTV[k] == 1)
    {
    }
    else if (CCTV[k] == 2)
    {}
    else if (CCTV[k] == 3)
    {}
    else if (CCTV[k] == 4)
    {}
    else if (CCTV[k] == 5)
    {}

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5)
            {
                CCTV[NUM_CCTV] = arr[i][j];
                loc_cctv[NUM_CCTV] = { i, j };
                NUM_CCTV++;
            } 
        }
    }

    backtracking(0);

    cout << min_cnt;

    return 0;
}