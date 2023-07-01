#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0; 
    long long sum = 0;
    int arr[1000005];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int day;
        int prof[1000005] = { 0 };

        sum = 0;
        cin >> day;

        for (int d = 0; d < day; d++)
        {
            cin >> arr[d];
            for (int j = 0; j <= d; j++)
            {
                if (arr[d] - arr[j] > prof[j])
                    prof[j] = arr[d] - arr[j];
            }
        }        

        for (int d = 0; d < day; d++)
        {
            if (prof[d] > 0)
                sum = sum + prof[d];
        }

        cout << sum << '\n';
    }

    return 0;
}