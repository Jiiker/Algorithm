#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N = 0, cnt = 0;
    pair<int, int> flower[100005];
    int end = 0;

    end = 301;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int month, day;
        cin >> month >> day;
        flower[i].second = (100 * month) + day;

        cin >> month >> day;
        flower[i].first = (100 * month) + day;
    }

    sort(flower, flower + N, greater<>());

    while (end <= 1130)
    {
        for (int i = 0; i < N; i++)
        {
            if (flower[i].second <= end)
            {
                cnt++;
                end = flower[i].first;
                break;
            }
            if (i == N - 1)
            {
                cout << 0;
                return 0;
            }
        }
    }

    cout << cnt;

    return 0;
}