#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    x = x * (x + 1) / 2;
    printf("%d", x);

    return 0;
}