#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    int i = 0, j = 0;
    int num = 0;
    int temp = 0;
    int* arr;

    scanf("%d", &N);
    arr = (int*)malloc(sizeof(int) * N);

    while (i < N)
    {
        scanf("%d", &num);
        arr[i] = num;
        i++;
    }

    i = 0;
    while (i < N)
    {
        j = 0;
        while (j < N - 1)
        {
            temp = 0;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }

    i = 0;
    while(i < N)
    {
        printf("%d", arr[i]);
        if (i != N - 1)
            printf("\n");
        i++;
    }
    return 0;
}