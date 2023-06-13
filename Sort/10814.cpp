#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int N = 0;
    pair<pair<int, int>, string> arr[105];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first.first >> arr[i].second;
        arr[i].first.second = i;
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
        cout << arr[i].first.first << ' ' << arr[i].second << '\n';

    return 0;
}