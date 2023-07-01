#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int MX = 10005;
    int dat[2*MX + 1];
    int head = MX, tail = MX;
    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front")
            cin >> dat[--head];
        else if (cmd == "push_back")
            cin >> dat[tail++];
        else if (cmd == "pop_front")
        {   
            if (head != tail)
                cout << dat[head++] << '\n';
            else
                cout << -1 << '\n';
        }
        else if (cmd == "pop_back")
        {
            if (head != tail) 
                cout << dat[--tail] << '\n';
            else
                cout << -1 << '\n';
        }
        else if (cmd == "size")
            cout << tail - head << '\n';
        else if (cmd == "empty")
        {
            if (tail == head)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "front")
        {
            if (tail == head)
                cout << -1 << '\n';
            else
                cout << dat[head] << '\n';
        }
        else if (cmd == "back")
        {
            if (tail == head)
                cout << -1 << '\n';
            else
                cout << dat[tail - 1] << '\n';
        }
    }

    return 0;
}