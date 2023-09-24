#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE* fp;
	int n, sum = 0;
	int* arr;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	arr = (int*)malloc(sizeof(int) * n);


	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d", &arr[i]);
		sum += arr[i];
	}


	fclose(fp);
	free(arr);

	FILE* fp_out = fopen("output.txt", "w");
	fprintf(fp_out, "%d\n", sum);
	fclose(fp_out);

	return 0;
}

/*  
input.txt
3
3 4 5

output.txt
12
*/