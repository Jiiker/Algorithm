#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string c;
    int num = 0;
    int sum = 0;
    int flag = 0;

    cin >> c;

    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
            num = (num * 10) + (c[i] - 48);
        if (c[i] == '+' && flag == 0)
        {
            sum = sum + num;
            num = 0;
        }
        if (c[i] == '-' && flag == 0)
        {
            flag = 1;
            sum = sum + num;
            num = 0;
        }
        if ((c[i] == '-' || c[i] == '+') && flag == 1)
        {
            sum = sum - num;
            num = 0;
        }
    }

    if (flag == 0)
        sum = sum + num;
    else
        sum = sum - num;
    
    cout << sum;

    return 0;
}