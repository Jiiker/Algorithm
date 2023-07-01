#include <bits/stdc++.h>

using namespace std;

int N = 0;
long long int arr[91];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[N];

    return 0;
}