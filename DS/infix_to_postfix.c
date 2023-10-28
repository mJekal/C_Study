#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100 /* maximum stack size */

char expr[1111];
typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;

precedence stack[MAX_STACK_SIZE];
/* isp and icp arrays index is value of precedence
lparen, rparen , plus, minus, times, divide, mod, eos */
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

int top = 0;

void push(precedence item) {
	if (top >= MAX_STACK_SIZE - 1) printf("stack is full\n");
	else stack[++top] = item;
}
precedence pop() {
	if (top == -1) printf("stack is empty");
	return stack[top--];
}
void printToken(precedence token) {
	switch (token) {
	case lparen: printf("("); break;
	case rparen: printf(")"); break;
	case plus: printf("+"); break;
	case minus: printf("-"); break;
	case divide: printf("/"); break;
	case times: printf("*"); break;
	case mod: printf("%%"); break;
	case eos: printf("\0"); break;
	}

}

precedence getToken(char* symbol, int* n) 
{
	/* get the next token, symbol is the character representation, which is returned, the
	token is represented by its enumerated value, which is returned in the function name */
	switch (*(symbol + *n)) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand; /* no error checking, default is operand */
	}
}

void postfix(void)
{ /* output the postfix of the expression. The expression string, stack, and the top are global */
	int n = 0;
	precedence token;

	stack[0] = eos;

	for (token = getToken(expr, &n); token != eos; token = getToken(expr, &n)) {
		if (token == operand) 
			printf("%c", expr[n]);
		else if (token == rparen) { 
			/* unstack tokens until left parenthesis */
			while (stack[top] != lparen)
				printToken(pop());
			pop();/* discard the left parenthesis */
		}
		else { 
			/* remove and print symbols whose isp is greater
			than or equal to the current token¡¯s icp */
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
		n++;
	}
	while ((token = pop()) != eos)
		printToken(token);
	printf("\n");
}

int main() {
	scanf("%s", expr);
	postfix();
	printf("%s\n", expr);
	return 0;
}