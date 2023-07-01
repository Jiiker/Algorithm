#include <bits/stdc++.h>

using namespace std;

int N = 0;
int arr[91];
int cnt = 0;

void back_tracking(int k)
{
    if (k == N)
    {
        cnt++;
        return;
    }

    if (k == 0)
    {
        arr[k] = 1;
        back_tracking(k + 1);
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (arr[k - 1] == 1 && i == 1)
            return;
        arr[k] = i;
        back_tracking(k + 1);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    back_tracking(0);

    cout << cnt;

    return 0;
}