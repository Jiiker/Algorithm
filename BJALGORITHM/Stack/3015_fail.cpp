#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0, cnt = 0;
    stack<pair<long long, int> > S;

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        long long height = 0;
        cin >> height;

        while (!S.empty() && height > S.top().first)
        {
            cnt = cnt + S.top().second;
            S.pop();
        }
        
        if (S.empty())
            S.push({height, 1});
        
        else if (height < S.top().first)
        {
            cnt++;
            S.push({height, 1});
        }
        else if (height == S.top().first)
        {
            int rep = S.top().second + 1;
            S.pop();
            
            if (!S.empty())
                cnt = cnt + rep;
            else
                cnt = cnt + rep - 1;

            S.push({height, rep});
        }
    }

    cout << cnt;

    return 0;
}