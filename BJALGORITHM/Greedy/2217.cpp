#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, max = 0;
    int arr[100001];

    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort(arr, arr + N, greater<int>());
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] * (i + 1) > max)
            max = arr[i] * (i + 1);
    }

    cout << max;

    return 0;
}