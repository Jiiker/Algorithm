#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int N;

int binarysearch(int num)
{
    int st = 0, en = N - 1;
    while (en >= st)
    {
        int mid = (st + en) / 2;

        if (num > arr[mid])
            st = mid + 1;
        else if (num < arr[mid])
            en = mid - 1;
        else
            return 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        int result;

        cin >> num;

        result = binarysearch(num);

        cout << result << '\n';
    }


    return 0;
}