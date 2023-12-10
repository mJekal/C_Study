#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


struct CompleteNode {
    char data;
    struct CompleteNode* left;
    struct CompleteNode* right;
};

typedef struct CompleteNode CompleteNode;


CompleteNode* createNode(char data) {
    CompleteNode* newNd = (CompleteNode*)malloc(sizeof(CompleteNode));
    if (newNd == NULL) {
        printf("메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }
    newNd->data = data;
    newNd->left = NULL;
    newNd->right = NULL;
    return newNd;
}


void inorderTraversal(CompleteNode * root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        if (root->data != 'N') {
            printf("%c", root->data);
        }
        inorderTraversal(root->right);
    }
}

void postorderTraversal(CompleteNode * root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        if (root->data != 'N') {
            printf("%c", root->data);
        }
    }
}

void preorderTraversal(CompleteNode * root) {
    if (root != NULL) {
        if (root->data != 'N') {
            printf("%c", root->data);
        }
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void freeTree(CompleteNode * root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {

    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("파일을 열 수 없음.\n");
        return 1;
    }


    int size;
    fscanf(file, "%d", &size);

    CompleteNode* root = NULL;
    CompleteNode* currentNd = NULL;

    for (int i = 0; i < size; i++) {
        char data;
        fscanf(file, " %c", &data);
        CompleteNode* newNd = createNode(data);

        if (i == 0) {
            root = newNd;
            currentNd = root;
        }
        else {
            
            if (i % 2 == 1) {
                currentNd->left = newNd;
            }
            else {
                currentNd->right = newNd;
            }
            currentNd = newNd;
        }
    }


    fclose(file);

    printf("inorder traversal: ");
    inorderTraversal(root);
    printf("\npreorder traversal: ");
    preorderTraversal(root);
    printf("\npostorder traversal: ");
    postorderTraversal(root);

    freeTree(root);

    return 0;
}
