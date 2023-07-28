#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    for (int i = 0; x > i; i++)
    {
        for (int j = x; j >= x - i; j--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
