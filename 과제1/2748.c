#include <stdio.h>

long long f[91];

long long fn(int x)
{
    if (x == 1)
        return 1;
    if (x == 2)
        return 1;
    if (f[x] != 0)
        return f[x];
    return f[x] = fn(x - 1) + fn(x - 2);
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%lld", fn(num));
}