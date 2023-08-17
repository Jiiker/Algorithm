#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase = 1;

    while (testcase >= 1)
    {
        int period, length, vacation;
        int cycle, remain, result;

        cin >> length >> period >> vacation;

        if (length == 0 && period == 0 && vacation == 0)
            return 0;

        cycle = vacation / period;
        remain = vacation - (cycle * period);

        if (remain >= length)
            result = length * cycle + length;
        else
            result = length * cycle + remain;

        cout << "Case " << testcase << ": " << result << '\n';
        testcase++;
    }

    return 0;
}