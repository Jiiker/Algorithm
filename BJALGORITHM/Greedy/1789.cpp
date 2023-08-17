#include <iostream>

using namespace std;

int main()
{
    int S = 0;
    int num = 1, count = 0;

    cin >> S;

    while (num > 0)
    {
        if (S < num)
            break;

        S = S - num;
        count++;
        num++;
    }

    cout << count;

    return 0;
}