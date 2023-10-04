#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int N) {
    int i, j, max, temp;
    double duration;
    clock_t start, end;
    start = clock();

    for (i = 0; i < N - 1; i++) {
        max = i;

        for (j = i + 1; j < N; j++) {
            if (arr[j] > arr[max])
                max = j;
        }

        if (i != max) {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("TIME: %lf\n", duration);
}

int main() {
    FILE* fp;
    int N;
    srand((unsigned int)time(NULL));

    scanf("%d", &N);

    int* arr;
    arr = (int*)malloc(sizeof(int) * N);

    fp = fopen("unsorted.txt", "w");

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    selection_sort(arr, N);

    FILE* fp_out = fopen("sorted.txt", "w");

    for (int i = 0; i < N; i++) {
        fprintf(fp_out, "%d ", arr[i]);
    }

    free(arr);
    fclose(fp_out);

    return 0;
}
