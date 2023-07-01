#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, end = 0, cnt = 0;
    pair<int, int> s[100005];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i].second >> s[i].first;

    sort(s, s + N);

    for (int i = 0; i < N; i++)
    {
        if (s[i].second >= end)
        {
            end = s[i].first;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}