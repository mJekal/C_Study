#include <stdio.h>

int main(void)
{
    int minval = 0;
    int k[9];
    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &k[i]);
    }
    for (int i = 0; i < 9; i++)
    {
        if (k[i] > minval)
        {
            minval = k[i];
            index = i;
        }
    }
    printf("%d\n%d", minval, index + 1);
    return 0;
}