#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A = 0;
    long long pow = 1;
    int C = 0, B = 0;

    cin >> A >> B >> C;

    A = A % C;

    while (B > 0)
    {
        if (B % 2 == 1)
            pow = (pow * A) % C;
        
        A = (A * A) % C;
        B = B / 2;
    }

    cout << pow;

    return 0;
}