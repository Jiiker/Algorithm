#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    pair<int, int> arr[100005];

    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';

    return 0;
}