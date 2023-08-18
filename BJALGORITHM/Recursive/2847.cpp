#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int cnt = 0;

void recursive_check(int num)
{
    if (S.empty())
        return;

    int top = S.top(); S.pop();

    if (top >= num)
    {
        cnt = cnt + (top - num + 1);
        top = num - 1;
    }

    recursive_check(top);

    S.push(top);
    
    return;
}

int main()
{
    int N = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        
        if (i == 0)
        {
            S.push(num);
            continue;
        }
        
        if (S.top() >= num)
            recursive_check(num);

        S.push(num);
    }

    cout << cnt;

    return 0;
}