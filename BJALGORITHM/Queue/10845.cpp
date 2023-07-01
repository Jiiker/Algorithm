#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dat[10005];
    int head = 0, tail = 0;
    int N = 0;
    string cmd;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;
        if (cmd == "push")
            cin >> dat[tail++];
        else if (cmd == "pop")
        {
            if (head == tail)
                cout << -1 << '\n';
            else
                cout << dat[head++] << '\n';
        }
        else if (cmd == "size")
            cout << tail - head << '\n';
        else if (cmd == "empty")
        {
            if (head == tail)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (head == tail)
                cout << -1 << '\n';
            else
                cout << dat[head] << '\n';
        }
        else if (cmd == "back")
        {
            if (head == tail)
                cout << -1 << '\n';
            else
                cout << dat[tail - 1] << '\n';
        }
    }

    return 0;
}