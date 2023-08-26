#include <stdio.h>

int main(void)
{
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", i, a + b);
    }
    return 0;
}
