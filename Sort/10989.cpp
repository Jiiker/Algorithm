#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int N = 0;
    int arr[10001] = { 0 };

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        cin >> num;
        arr[num]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }

    return 0;
}