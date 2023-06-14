#include <bits/stdc++.h>

using namespace std;

int L = 0, C = 0;
char arr[20] = { 0 };
int vis[20] = { 0 };
char code[20] = { 0 };
int cons = 0, vow = 0;

void hacking(int k)
{
    if (k == L)
    {
        if (cons >= 2 && vow >= 1)
        {
            for (int i = 0; i < L; i++)
                cout << code[i];
            cout << '\n';
        }
        return;
    }

    for (int i = 0; i < C; i++)
    {
        if (vis[i] == 1)
            continue;
        if (k > 0 && arr[i] < code[k - 1])
            continue;

        code[k] = arr[i];
        vis[i] = 1;
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            vow++;
        else
            cons++;
        hacking(k + 1);
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            vow--;
        else
            cons--;
        vis[i] = 0;
   }

   return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
        cin >> arr[i];

    sort(arr, arr + C);

    hacking(0);

    return 0;
}