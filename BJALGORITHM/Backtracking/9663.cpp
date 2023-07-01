#include <bits/stdc++.h>

using namespace std;

int N = 0, cnt = 0;
int board[15][15] = { 0 };

int check_left(int i, int j)
{
    for (int k = 1; k <= j; k++)
    {
        if (j - k >= 0 && board[i][j - k] == 1)
            return 0;
        if (i + k < 15 && j - k >= 0 && board[i + k][j - k] == 1)
            return 0;
        if (i - k >= 0 && j - k >= 0 && board[i - k][j - k] == 1)
            return 0;
    }

    return 1;
}

void back_tracking(int N, int k)
{
    if (k == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (check_left(i, k) == 1)
        {
            board[i][k] = 1;
            back_tracking(N, k + 1);
            board[i][k] = 0;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    back_tracking(N, 0);

    cout << cnt;

    return 0;
}