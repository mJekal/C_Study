#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    int A, B;
    scanf("%d %d", &A, &B);
    if (A > B) {
        printf("A");
    }
    else if (B > A) {
        printf("B");
    }
    else {
        printf("same");
    }

    return 0;
}
