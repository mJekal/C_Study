#include <stdio.h>

int main(void)
{
    int H, M;
    scanf("%d %d", &H, &M);
    if (M < 45)
    {
        M += 15;
        H -= 1;
    }
    else if (M >= 45)
    {
        M = -45;
    }
    if (H == -1)
    {
        H = 23;
    }
    printf("%d %d", H, M);
    return 0;
}