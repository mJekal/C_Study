#include <stdio.h>

int main()
{
    int k;
    int n;
    int m;
    int arr[15][15] = {
        0,
    };
    scanf("%d", &k);
    for (int i = 1; i < 15; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < 15; i++)
    {
        arr[i][0] = 0;
        for (int j = 1; j < 15; j++)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &n);
        scanf("%d", &m);
        printf("%d\n", arr[n][m]);
    }
    return 0;
}