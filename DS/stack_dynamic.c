#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) if (!((p) = malloc(s))) {\
    fprintf(stderr, "Insufficient memory"); \
    exit(EXIT_FAILURE); \
}


typedef struct
{
    int key;
    /* other fileds */
} element;

element* stack;
int capacity = 1;
int top = -1;


void push(element item)
{
    /* add an item to the global stack */
    if (top >= capacity- 1)
    {
        stackFull();
    }
    stack[++top] = item;
}

void stackFull()
{
    stack = realloc(stack, sizeof(element) * 2 * capacity);
    capacity *= 2;
}

element pop() {
    /* delete and return the top element from the stack */
    if (top == -1)
    {
        stackEmpty();
    }
    return stack[top--];
}

void stackEmpty()
{
    fprintf(stderr, "Stack is empty, cannot delete element");
    exit(EXIT_FAILURE);
}

int main(void)
{
    MALLOC(stack, sizeof(element) * capacity);
    // stack = (element*)malloc(sizeof(element) * capacity);
    free(stack);
    return 0;
}