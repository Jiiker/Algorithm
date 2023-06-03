#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    int arr[1005];
    int sum = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr, arr + N);

    for (int i = 1; i < N; i++)
        arr[i] = arr[i] + arr[i - 1];

    for (int i = 0; i < N; i++)
        sum = sum + arr[i];

    cout << sum;
    
    return 0;
}