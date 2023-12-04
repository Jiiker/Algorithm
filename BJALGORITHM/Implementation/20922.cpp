#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    int arr[200000] = { 0 };
    int check[100001] = { 0 };
    int max_len = 0;
    queue<int> Q;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        while (check[arr[i]] == K)
        {
            int num = Q.front(); Q.pop();
            check[num]--;
        }

        Q.push(arr[i]);
        check[arr[i]]++;

        if (Q.size() > max_len)
            max_len = Q.size();
    }

    cout << max_len;

    return 0;
}