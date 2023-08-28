#include <stdio.h>
#include <stdlib.h>

// Node
struct Node
{
    char name;
    struct Node *next;
};

// Node를 만드는 함수
struct Node *makeNode(char name)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->name = name;
    node->next = NULL;
    return node;
}

// curNode를 name을 가진 Node의 next에 두는 함수
void nextTo(struct Node *curNode, struct Node *head, char name)
{
    struct Node *curNode1 = head;

    while (curNode1 != NULL)
    {
        if (curNode1->name == name)
        {
            curNode->next = curNode1->next;
            curNode1->next = curNode;
            break;
        }
        curNode1 = curNode1->next;
    }
}

int main()
{
    struct Node *curNode = makeNode('A');
    // head Node 는 늘 가장 왼쪽의 Node를 가리킨다.
    struct Node *head = curNode;

    curNode = makeNode('B');
    nextTo(curNode, head, 'A'); // 현재 순서는 A->B

    curNode = makeNode('C');
    nextTo(curNode, head, 'B'); // 현재 순서는 A->B->C

    curNode = makeNode('D');
    nextTo(curNode, head, 'B'); // 현재 순서는 A->B->D->C

    // 순서를 출력하는 함수
    curNode = head;
    while (curNode != NULL)
    {
        printf("%c\n", curNode->name);
        curNode = curNode->next;
    }

    return 0;
}