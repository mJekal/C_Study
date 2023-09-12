#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int factorial(int n)
{
	int res = 1;

	for (int i = n; i >= 1; i--)
		res *= i;

	return res;
}


void sum(int n, int k)
{
	int res = 0;

	while (n != 0) {
		res += factorial(n % 10);
		n /= 10;
	}

	k--;

	printf(" %d", res);

	if (k == 1)
		return 0;

	sum(res, k);
}


int main()
{
	int N, K, list[1000] = { 0 };
	scanf("%d %d", &N, &K);
	printf("%d", N);
	sum(N, K);
}