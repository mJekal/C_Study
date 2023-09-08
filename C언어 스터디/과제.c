#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[] = {1, 1, 1, 1, 2, 4, 4, 5, 7, 7, 7};
    // int A[] = {1,2, 4, 5, 7};
    int len = sizeof(A) / sizeof(A[0]);
    int length = A[len - 1] + 1;
    int *B = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        B[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        B[A[i]]++;
    }

    for (int i = 0; i < length; i++)
    {
        if (B[i] >= 2)
        {
            printf("%d (%d번), ", i, B[i]);
        }
    }

    return 0;
}