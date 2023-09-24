#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp;
	int n, sum = 0;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 1; i <= n; i++) {
		sum += i;
	};


	fclose(fp);

	FILE* fp_out = fopen("output.txt", "w");
	fprintf(fp_out, "%d\n", sum);
	fclose(fp_out);

	return 0;

}


/*  
input.txt
6

output.txt
21
*/