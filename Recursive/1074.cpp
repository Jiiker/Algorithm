#include <bits/stdc++.h>

using namespace std;

int N, r, c;
int cnt = 0;

int two_pow(int n)
{
    int pow = 1;
    for (int i = 0; i < n; i++)
        pow = pow * 2;
    
    return pow;
}

void cross(int std_x, int std_y, int std)
{
    if (std < 1)
    {
        cout << cnt;
        return;
    }

    if (c <= std_x && r <= std_y)
    {
        cnt = cnt + (std * std * 0);
        cross(std_x - (std / 2), std_y - (std / 2), std / 2);
    }
    else if (c > std_x && r <= std_y)
    {
        cnt = cnt + (std * std * 1);
        cross(std_x + (std / 2), std_y - (std / 2), std / 2);
    }
    else if (c <= std_x && r > std_y)
    {
        cnt = cnt + (std * std * 2);
        cross(std_x - (std / 2), std_y + (std / 2), std / 2);
    }
    else if (c > std_x && r > std_y)
    {
        cnt = cnt + (std * std * 3);
        cross(std_x + (std / 2), std_y + (std / 2), std / 2);
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;
    r = r + 1;
    c = c + 1;

    cross(two_pow(N - 1), two_pow(N - 1), two_pow(N - 1));

    return 0;
}