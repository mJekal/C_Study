#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void matrix_mul(int n, int* arr1[], int* arr2[], int* ans[]) {
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    FILE* fp_out = fopen("output.txt", "w");
    
  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp_out, "%d ", ans[i][j]);
        }
        fprintf(fp_out, "\n");
    }

    fclose(fp_out);
}

int main() {
    FILE* fp;
    int n;

    fp = fopen("input.txt", "r");

    fscanf(fp, "%d", &n);
    fscanf(fp, "\n");

    int** arr1 = (int**)malloc(sizeof(int*) * n);
    int** arr2 = (int**)malloc(sizeof(int*) * n);
    int** ans = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        arr1[i] = (int*)malloc(sizeof(int) * n);
        arr2[i] = (int*)malloc(sizeof(int) * n);
        ans[i] = (int*)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &arr1[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &arr2[i][j]);
        }
    }

    fclose(fp);

    matrix_mul(n, arr1, arr2, ans);

    for (int i = 0; i < n; i++) {
        free(arr1[i]);
        free(arr2[i]);
        free(ans[i]);
    }
    free(arr1);
    free(arr2);
    free(ans);

    return 0;
}
