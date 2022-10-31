#include <stdlib.h>
#include <string.h>

#include "Eval.h"
#include "Stack.h"

int ord(char op)
{
	switch (op) {
	case '*':
	case '/':
		return 2;
		
	case '+':
	case '-':
		return 1;
		
	case '(':
		return 0;
	}
}

void convert_postfix_exp(char exp[])
{
	int idx = 0;
	int i, exp_len = strlen(exp);
	char tok, * conv_exp = (char *)malloc(exp_len + 1);
	Stack op_stack;
	
	init_stack(&op_stack);
	
	for (i = 0; i < exp_len; i++) {
		tok = exp[i];
		
		if ('0' <= tok && tok <= '9')
			conv_exp[idx++] = tok;
			
		else {
			switch (tok) {
			case '(':
				push(&op_stack, tok);
				break;
					
			case ')':
				while (peek(&op_stack) != '(')
					conv_exp[idx++] = pop(&op_stack);	
				pop(&op_stack);
				break;
					
			default:
				while (!is_empty(&op_stack) && !(ord(peek(&op_stack)) < ord(tok)))
					conv_exp[idx++] = pop(&op_stack);
				push(&op_stack, tok);
				break;
			}
		}
	}
	
	while(!is_empty(&op_stack))
		conv_exp[idx++] = pop(&op_stack);
		
	conv_exp[idx++] = '\0';
	strcpy(exp, conv_exp);
	free(conv_exp);
}

char eval(char exp[])
{
	int i, exp_len;
	char tok, * _exp = (char *)malloc(strlen(exp) + 1);
	Stack num_stack;
	
	init_stack(&num_stack);
	strcpy(_exp, exp);
	convert_postfix_exp(_exp);
	exp_len = strlen(_exp);
	
	for (i = 0; i < exp_len; i++) {
		tok = _exp[i];
		
		if ('0' <= tok && tok <= '9')
			push(&num_stack, tok - '0');
			
		else {
			char a = pop(&num_stack);
			char b = pop(&num_stack);
			
			switch (tok) {
			case '+':
				push(&num_stack, b + a);
				break;
			case '-':
				push(&num_stack, b - a);
				break;
			case '*':
				push(&num_stack, b * a);
				break;
			case '/':
				push(&num_stack, b / a);
				break;
			}
		}
	}
	
	free(_exp);
	return pop(&num_stack);
}
