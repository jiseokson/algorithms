#include <stdio.h>
#include <string.h>
#include "Stack.h"

int get_ord(char op)
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

convert_postfix_exp(char exp[])
{
	char conv_exp[50], tok;
	int idx = 0;
	int i, exp_len = strlen(exp);
	Stack op_stack;
	
	init_stack(&op_stack);
	
	for (i = 0; i < exp_len; i++) {
		tok = exp[i];
		
		if (tok == ' ')
			continue;
			
		else if ('0' <= tok && tok <= '9')
			conv_exp[idx++] = tok;
			
		else {
			if (is_empty(&op_stack))
				push(&op_stack, tok);
			
			else {
				if (tok == '(')
					push(&op_stack, tok);
				
				else if(tok == ')') {
					while (peek(&op_stack) != '(')
						conv_exp[idx++] = pop(&op_stack);
						
					pop(&op_stack);
				}
				
				else {
					while (!(get_ord(peek(&op_stack)) < get_ord(tok)))
						conv_exp[idx++] = pop(&op_stack);
						
					push(&op_stack, tok);
				}
			}
		}
	}
	
	while(!is_empty(&op_stack))
		conv_exp[idx++] = pop(&op_stack);
		
	conv_exp[idx++] = '\0';
	strcpy(exp, conv_exp);
}

int main(void)
{
	char exp1[] = "1 + 2 * 3";
	char exp2[] = "(1 + 2) * 3";
	char exp3[] = "((1 - 2) + 3) * (5 - 2)";
	
	convert_postfix_exp(exp1);
	convert_postfix_exp(exp2);
	convert_postfix_exp(exp3);
	
	puts(exp1);
	puts(exp2);
	puts(exp3);
	
	return 0;
}
