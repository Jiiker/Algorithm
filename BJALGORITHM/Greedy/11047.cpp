#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, K = 0, cnt = 0;
    stack<int> S;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int coin = 0;
        cin >> coin;

        S.push(coin);
    }

    for (int i = 0; i < N; i++)
    {
        int coin = S.top();
        S.pop();

        cnt = cnt + K / coin;
        K = K % coin;
    }

    cout << cnt;
    
    return 0;
}