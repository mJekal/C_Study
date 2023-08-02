#include <stdio.h>

int main(void)
{
    int n, X;
    scanf("%d %d", &n, &X);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a < X)
        {
            printf("%d ", a);
        }
    }
    return 0;
}