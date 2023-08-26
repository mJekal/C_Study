#include <stdio.h>

int main(void)
{
    int H, M, K;
    int ans;
    int max;
    scanf("%d %d %d", &H, &M, &K);
    if (M == H && H == K)
    {
        ans = 10000 + H * 1000;
    }
    else if (M == H && H != K || H == K && M != K)
    {
        ans = 1000 + H * 100;
    }
    else if (M == K && H != K)
    {
        ans = 1000 + M * 100;
    }
    else
    {
        max = M;
        if (K > max)
        {
            max = K;
        };
        if (H > max)
        {
            max = H;
        };
        ans = max * 100;
    }
    printf("%d", ans);
    return 0;
}