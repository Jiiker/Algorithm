#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K = 0;
    int sum = 0;
    stack<int> S;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int num = 0;
        cin >> num;

        if (num == 0)
        {
            sum = sum - S.top();
            S.pop();
        }
        else
        {
            sum = sum + num;
            S.push(num);
        }
    }

    cout << sum;

    return 0;
}