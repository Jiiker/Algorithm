#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int arr[100005];
    int vis[100005] = { 0 };
    queue<int> Q;
    cin >> N >> K;

    Q.push(N);
    arr[N] = 0;
    vis[N] = 1;
    while(1)
    {
        int cur = Q.front();
        Q.pop();
        if (cur == K)
            break;
        if (2 * cur <= 100000 && vis[2 * cur] == 0)
        {
            Q.push(2 * cur);
            arr[2 * cur] = arr[cur] + 1;
            vis[2 * cur] = 1;
        }
        if (cur - 1 >= 0 && vis[cur - 1] == 0)
        {
            Q.push(cur - 1);
            arr[cur - 1] = arr[cur] + 1;
            vis[cur - 1] = 1;
        }
        if (cur + 1 <= 100000 && vis[cur + 1] == 0)    
        {
            Q.push(cur + 1);
            arr[cur + 1] = arr[cur] + 1;
            vis[cur + 1] = 1;
        }
    }

    cout << arr[K];

    return 0;
}