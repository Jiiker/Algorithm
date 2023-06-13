#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dat[100005];
    int pos = 0;
    int K = 0;
    int sum = 0;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int N = 0;

        cin >> N;
        if (N == 0)
        {
            if (pos != 0)
                pos--;
        }
        else
            dat[pos++] = N;

    }

    for (int i = 0; i < pos; i++)
        sum = sum + dat[i];

    cout << sum;

    return 0;
}