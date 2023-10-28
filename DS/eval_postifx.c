#include <stdio.h>
#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100 /* maximum stack size */

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1) printf("stack is full\n");
	else stack[++top] = item;
}
int pop() {
	if (top == -1) printf("stack is empty");
	return stack[top--];
}

precedence getToken(char* symbol, int* n)
{
	/* get the next token, symbol is the character representation, which is returned, the
	token is represented by its enumerated value, which is returned in the function name */
	expr[++(*n)] = *(symbol + *n);
	switch (*(symbol + *n)) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case ' ': return eos;
	default: return operand; /* no error checking, default is operand */
	}
}

int eval(char* symbol)
{ /* evaluate a postfix expression, expr, maintained as a global variable. '\0' is the end of the
	expression. The stack and top of the stack are global variables. getToken is used to
	return the tokentype and the character symbol. Operands are assumed to be single
	character digits */
	precedence token;
	int op1, op2;
	int n = -1; /* counter for the expression string */
	token = getToken(symbol, &n);

	while (token != eos) {
		if (token == operand)
			push(symbol[n] - '0'); /* stack insert */
		else
		{ /* remove two operands, perform operation, and return result to the stack */
			op2 = pop(); /* stack delete */
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2); break;
			case minus: push(op1 - op2); break;
			case times: push(op1 * op2); break;
			case divide: push(op1 / op2); break;
			case mod: push(op1 % op2);
			}
		}
		token = getToken(symbol, &n);
	}
	return pop(); /* return result */
}


int main() {
	char Token[10] = { '6', '2', '/', '3', '-', '4', '2', '*', '+', ' ' };
	int result;
	result = eval(Token);

	printf("result : %d", result);
	return 0;
}