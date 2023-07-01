#include <bits/stdc++.h>

using namespace std;

int N = 0;
int arr[50] = { 0 };
int used[50] = { 0 };
int lotto[50] = { 0 };

void raffle(int k, int flag)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << lotto[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = flag; i < N; i++)
    {
        if (used[i] == 1)
            continue;
        lotto[k] = arr[i];
        used[i] = 1;
        raffle(k + 1, i);
        used[i] = 0;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> N;
        if (N == 0)
            break;
        
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        
        raffle(0, 0);
    }

    return 0;
}