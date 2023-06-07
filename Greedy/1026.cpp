#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N =0;
    int arr_A[55];
    int arr_B[55];
    int vis[55] = { 0 };
    int max = 0, min = 100;
    int max_i = 0, min_j = 0;
    int result = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr_A[i];
    for (int j = 0; j < N; j++)
        cin >> arr_B[j];
    
    for (int k = 0; k < N; k++)
    {
        int temp = 0;
        max = 0;
        min = 100;
        for (int i = 0; i < N; i++)
        {
            if (arr_A[i] >= max && vis[i] != 1)
            {
                max_i = i;
                max = arr_A[i];
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (arr_B[j] <= min && vis[j] != 1)
            {
                min_j = j;
                min = arr_B[j];
            }
        }

        temp = arr_A[max_i];
        arr_A[max_i] = arr_A[min_j];
        arr_A[min_j] = temp;
        vis[min_j] = 1;
    }

    for (int i = 0; i < N; i++)
        result = result + (arr_A[i] * arr_B[i]);
    
    cout << result;
    
    return 0;
}