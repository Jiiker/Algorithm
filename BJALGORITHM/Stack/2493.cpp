#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int top[500001];
    int idx[500001] = { 0 };
    stack<pair<int, int> > S;
    int N = 0;

    cin >> N;

    S.push({0, 0});
    for (int i = 0; i < N; i++)
    {
        cin >> top[i];
        while(!S.empty())
        {
            pair<int, int> cur = S.top();

            if (top[i] > cur.first)
                S.pop();
            if (top[i] < cur.first)
            {
                idx[i] = cur.second + 1;
                break;
            }
        }
        S.push({top[i], i});
    }

    for (int i = 0; i < N; i++)
        cout << idx[i] << ' ';

    return 0;
}