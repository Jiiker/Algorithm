#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S[100005];
    int out[100005];
    int n = 0, bef = 0, cur = 0, max = 0, flag = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        cur = num;
        out[num] = 1;
        S[i] = num;

        if (flag == 0 & cur < max)
        {
            for (int i = cur; i <= max; i++)
            {
                if (out[i] == 0)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
        if (flag == 1 && cur > bef)
        {
            cout << "NO";
            return 0;
        }

        if (num > max)
            max = num;
        if (num == n)
            flag = 1;
        
        bef = cur;
    }

    max = 0;
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        cur = S[i];
        if (flag == 0 && cur > max)
        {
            for (int j = 0; j < cur - max; j++)
                cout << '+' << '\n';
            cout << '-' << '\n';
        }
        if (flag == 0 && cur < max)
            cout << '-' << '\n';
        if (flag == 1)
            cout << '-' << '\n';
        
        if (cur > max)
            max = cur;    
        if (max == n)
            flag = 1;
    }
    return 0;
}