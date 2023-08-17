#include <iostream>

using namespace std;

int main()
{
    int N = 0;
    int five = 0, three = 0, result = 0;

    cin >> N;

    while (N % 5 != 0 && N > 0)
    {
        N = N - 3;
        result++;
    }

    if (N % 5 != 0)
    {
        cout << -1;
        return 0;
    }

    result = result + (N / 5);

    cout << result;

    return 0;
}