#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinarySearch(int* arr, int n, int m)
{

    int last, start, mid;

    last = n - 1;
    start = 0;

    while (start <= last)
    {
        mid = (start + last) / 2;
        if (arr[mid] == m)
        {
            return mid;
        }
        else if (arr[mid] > m)
        {
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    FILE* fp;
    int n, m, ans;
    int* arr;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d %d", &n, &m);
    arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    ans = BinarySearch(arr, n, m);

    free(arr);

    FILE* fp_out = fopen("output.txt", "w");
    fprintf(fp_out, "%d\n", ans);
    fclose(fp_out);

    return 0;
}

/*
input.txt
6 2
-11 -6 -3 1 2 9

output.txt
4
*/
