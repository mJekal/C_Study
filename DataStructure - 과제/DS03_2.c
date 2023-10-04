#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
	char ISBM[11] = { 0 };
	scanf("%s", ISBM);
	int idx = 0, sum = 0, check_isbm[11] = { 0 }, len = strlen(ISBM), cnt = 0, num = 10;
	for (int i = 0; i < len; i++)
	{
		if ('0' <= ISBM[i] && ISBM[i] <= '9')
			check_isbm[i] = ISBM[i] - '0';

		else if (ISBM[i] == 'X')
			check_isbm[i] = 10;

		else
		{
			check_isbm[i] = 0;
			idx = i;
		}
	}

	for (int i = 0; i < len; i++)
	{
		sum += check_isbm[i] * num;
		num--;
	}

	for (;;)
	{
		check_isbm[idx]++;
		sum += (check_isbm[idx]) * (10 - idx);
		if (sum % 11 == 0)
		{
			if (check_isbm[idx] != 10)
				printf("Missing Digit: %d", check_isbm[idx]);
			else
				printf("Missing Digit: X");
			break;
		}
		else
			sum -= check_isbm[idx] * (10 - idx);

	}
}