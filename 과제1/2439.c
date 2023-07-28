#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    for (int i = 1; x >= i; i++)
    {
        for (int j = 0; j < x - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
