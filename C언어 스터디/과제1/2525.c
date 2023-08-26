#include <stdio.h>

int main(void)
{
    int H, M;
    int C;
    scanf("%d %d", &H, &M);
    scanf("%d", &C);
    M = M + C;
    if (M >= 60)
    {
        H = H + M / 60;
        M = M % 60;
    }
    if (H > 23)
    {
        H = H % 24;
    }
    printf("%d %d", H, M);
    return 0;
}