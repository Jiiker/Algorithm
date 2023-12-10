#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0; 
    int arr[1000005];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int day;
        int prof[1000005] = { 0 };
        int max_value = 0;
        long long sum = 0;
        cin >> day;

        for (int d = 0; d < day; d++)
        {
            cin >> arr[d];
        }        

        for (int d = day - 1; d >= 0; d--)
        {
            if (arr[d] > max_value)
                max_value = arr[d];
            else if (arr[d] < max_value)
                sum = sum + (max_value - arr[d]);
        }
        cout << sum << '\n';
    }

    return 0;
}