#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int compare(const void *a, const void *b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;

    return 0;        
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int arr[1000005];
    int N = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    qsort(arr, N, sizeof(int), compare);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}