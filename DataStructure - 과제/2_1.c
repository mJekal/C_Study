#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[101];
int capacity = -1;
int top = -1;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0, 7, 6, 10, 10, 9, 9, 8, 8 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0, 7, 6, 10, 10, 9, 9, 8, 8 };

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand,
    and_op,   
    or_op,    
    eq_op,    
    ne_op,    
    lt_op,    
    gt_op,   
    le_op,   
    ge_op     
} precedence;

precedence Token(char c)
{
    switch (c)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '/':
        return divide;
    case '*':
        return times;
    case '%':
        return mod;
    case '&':
        return and_op;
    case '|':
        return or_op;
    case '=':
        return eq_op;
    case '!':
        return ne_op;
    case '<':
        return lt_op;
    case '>':
        return gt_op;
    default:
        return operand;
    }
}

char* changeToken(precedence token)
{
    switch (token)
    {
    case lparen:
        return "(";
    case rparen:
        return ")";
    case plus:
        return "+";
    case minus:
        return "-";
    case divide:
        return "/";
    case times:
        return "*";
    case mod:
        return "%";
    case and_op:
        return "&&";
    case or_op:
        return "||";
    case eq_op:
        return "==";
    case ne_op:
        return "!=";
    case lt_op:
        return "<";
    case gt_op:
        return ">";
    case le_op:
        return "<=";
    case ge_op:
        return ">=";
    default:
        return NULL;
    }
}

void push(int data)
{
    stack[++top] = data;
}

int pop()
{
    return stack[top--];
}

void Posfix(char* infix, char* postfix)
{
    int now = 0;
    int cur = 0;
    int len = strlen(infix);
    push(eos);

    while (now < len)
    {
        char item = infix[now++];
        precedence token = Token(item);

        if (token == operand)
            postfix[cur++] = item;
        else if (token == rparen)
        {
            while (stack[top] != lparen)
            {
                char* tmp = changeToken(pop());
                strcat(postfix, tmp);
                cur += strlen(tmp);
            }
            pop(); 
        }
        else
        {
            while (isp[stack[top]] >= icp[token])
            {
                char* tmp = changeToken(pop());
                strcat(postfix, tmp);
                cur += strlen(tmp);
            }
            push(token);
        }
    }

    while (stack[top] != eos)
    {
        char* temp = changeToken(pop());
        strcat(postfix, temp);
        cur += strlen(temp);
    }
}

int eval(char* postfix)
{
    char token;
    int op1, op2;

    for (int i = 0; postfix[i] != 0; i++)
    {
        token = postfix[i];

        if (Token(token) == operand)
            push(token - '0');
        else
        {
            op1 = pop();
            op2 = pop();

            switch (Token(token))
            {
            case times:
                push(op2 * op1);
                break;
            case divide:
                push(op2 / op1);
                break;
            case mod:
                push(op2 % op1);
                break;
            case plus:
                push(op2 + op1);
                break;
            case minus:
                push(op2 - op1);
                break;
            case and_op:
                push(op2 && op1);
                break;
            case or_op:
                push(op2 || op1);
                break;
            case eq_op:
                push(op2 == op1);
                break;
            case ne_op:
                push(op2 != op1);
                break;
            case lt_op:
                push(op2 < op1);
                break;
            case gt_op:
                push(op2 > op1);
                break;
            case le_op:
                push(op2 <= op1);
                break;
            case ge_op:
                push(op2 >= op1);
                break;
            }
        }
    }
    return pop();
}

int main(void)
{
    FILE* f;
    char infix[101] = { 0 };
    char postfix[101] = { 0 };

    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("파일을 열 수 없음.\n");
        return 1;
    }
    fscanf(f, "%s", infix);
    Posfix(infix, postfix);

    printf("To_Postfix: %s\n", postfix);
    printf("답: %d\n", eval(postfix));
    fclose(f);
    return 0;
}
