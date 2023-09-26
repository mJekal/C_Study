#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int H1, H2, M1, M2, ans, Fsum = 0, Lsum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d:%d %d:%d", &H1, &M1, &H2, &M2);
        Fsum += H1 * 60 + M1;
        Lsum += H2 * 60 + M2;
    }
    ans = Lsum - Fsum;

    printf("%d", ans);
    return 0;
}