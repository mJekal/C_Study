#include <stdio.h>
#define MAX_STACK_SIZE 100 /* maximum stack size */

typedef struct
{
    int key;
    /* other fileds */
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item)
{
    /* add an item to the global stack */
    if (top >= MAX_STACK_SIZE - 1)
    {
        stackFull();
    }
    stack[++top] = item;
}

void stackFull()
{
    fprintf(stderr, "Stack is full, cannot add element");
    exit(1);
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
    exit(1);
}

int main(void)
{
    return 0;
}