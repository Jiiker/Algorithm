#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K = 0;
    int pow = 1;
    int cnt = 0;

    cin >> K;

    for (int i = 0; i < 20; i++)
    {
        if (K <= pow)
            break;
        pow = pow * 2;
    }

    cout << pow << ' ';
    
    while (pow >= 1)
    {
        if (K >= pow)
            K = K - pow;
        if (K == 0)
            break;
        
        pow = pow / 2;
        cnt++;
    }

    cout << cnt;

    return 0;
}