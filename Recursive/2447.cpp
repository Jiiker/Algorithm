#include <bits/stdc++.h>

using namespace std;

int N;
char arr[6600][6600] = { '\0' };

void star_print(int n)
{
    if (n > N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << arr[i][j];
            cout << '\n';    
        }

        return;
    }

    for (int i = 0; i < N / n; i++)
    {
        for (int j = 0; j < N / n; j++)
        {
            for (int x = (n / 3) + (n * i); x < (2 * n / 3) + (n * i); x++)
            {
                for (int y = (n / 3) + (n * j); y < (2 * n / 3) + (n * j); y++)
                {
                    arr[x][y] = ' ';
                }
            }
        }
    }

    star_print(3 * n);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            arr[i][j] = '*';
    }

    star_print(3);    

    return 0;
}