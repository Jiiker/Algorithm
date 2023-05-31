#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];
int vis[10] = { 0 };

void print_num(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] == 0)
        {
            arr[k] = i;
            vis[i] = 1;
            print_num(k + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> N >> M;

    print_num(0);
    
    return 0;
}