#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 10000

char nodes[MAX_SIZE];

void inorderTraversal(int index, int size) {
    if (index < size && nodes[index] != 'N') {
        inorderTraversal(2 * index + 1, size);
        printf("%c", nodes[index]);
        inorderTraversal(2 * index + 2, size);
    }
}

void postorderTraversal(int index, int size) {
    if (index < size && nodes[index] != 'N') {
        postorderTraversal(2 * index + 1, size);
        postorderTraversal(2 * index + 2, size);
        printf("%c", nodes[index]);
    }
}

void preorderTraversal(int index, int size) {
    if (index < size && nodes[index] != 'N') {
        printf("%c", nodes[index]);
        preorderTraversal(2 * index + 1, size);
        preorderTraversal(2 * index + 2, size);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("파일 열 수 없는 오류.\n");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    for (int i = 0; i < 100; i++) {
        fscanf(file, " %c", &nodes[i]);
    }

    fclose(file);

    printf("inorder traversal: ");
    inorderTraversal(0, 30);
    printf("\npreorder traversal: ");
    preorderTraversal(0, 30);
    printf("\npostorder traversal: ");
    postorderTraversal(0, 30);
    return 0;
}
