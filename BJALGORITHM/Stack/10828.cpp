#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dat[10005];
    int pos = 0;
    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string cmd;

        cin >> cmd;

        if (cmd == "push")
            cin >> dat[pos++];
        else if (cmd == "pop")
        {
            pos--;
            if (pos < 0)
            {
                cout << -1 << '\n';
                pos++;
                continue;
            }
            cout << dat[pos] << '\n';
        }
        else if (cmd == "size")
            cout << pos << '\n';
        else if (cmd == "empty")
        {
            if (pos == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "top")
        {
            if (pos == 0)
                cout << -1 << '\n';
            else
            {
                cout << dat[--pos] << '\n';
                pos++;
            }
        }
    }

    return 0;
}