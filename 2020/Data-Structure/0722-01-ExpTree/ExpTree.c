#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "BTree.h"

BTreeNode * make_exp_tree(char postfix_exp[])
{
	int i, exp_len = strlen(postfix_exp);
	char token;
	Stack stack;
	
	init_stack(&stack);
	
	for (i = 0; i < exp_len; i++) {
		BTreeNode * temp = make_BTreeNode();
		token = postfix_exp[i];
		
		if ('0' <= token && token <= '9')
			set_data(temp, token - '0');
			
		else {
			set_data(temp, token);
			make_right_subtree(temp, pop(&stack));
			make_left_subtree(temp, pop(&stack));
		}
		
		push(&stack, temp);
	}
	
	return pop(&stack);
}

int eval_exp_tree(BTreeNode * bt)
{
	if (bt -> left == NULL && bt -> right == NULL)
		return bt -> data;
		
	int op1 = eval_exp_tree(bt -> left);
	int op2 = eval_exp_tree(bt -> right);
	switch (bt -> data) {
	case '+':
		return op1 + op2;
		
	case '-':
		return op1 - op2;
		
	case '*':
		return op1 * op2;
		
	case '/':
		return op1 / op2;
	}
}

void show_prefix_exp(BTreeNode * bt)
{
	if (bt == NULL)
		return;
		
	if (0 <= bt -> data && bt -> data <= 9)
		printf("%d ", bt -> data);
	else
		printf("%c ", bt -> data);
	
	show_prefix_exp(bt -> left);
	show_prefix_exp(bt -> right);
}

void show_infix_exp(BTreeNode * bt)
{
	if (bt == NULL)
		return;
	/*
	if (0 <= bt -> data && bt -> data <= 9) {
		show_infix_exp(bt -> left);
		printf("%d ", bt -> data);
		show_infix_exp(bt -> right);
	}
	
	else {
		printf("( ");
		show_infix_exp(bt -> left);
		printf("%c ", bt -> data);
		show_infix_exp(bt -> right);
		printf(") ");
	}*/
	
	if (bt -> left != NULL && bt -> right != NULL)
		printf("( ");
		
	show_infix_exp(bt -> left);
	
	if (0 <= bt -> data && bt -> data <= 9)
		printf("%d ", bt -> data);
	else
		printf("%c ", bt -> data);
	
	show_infix_exp(bt -> right);
	
	if (bt -> left != NULL && bt -> right != NULL)
		printf(") ");
}

void show_postfix_exp(BTreeNode * bt)
{
	if (bt == NULL)
		return;
		
	show_postfix_exp(bt -> left);
	show_postfix_exp(bt -> right);
	
	if (0 <= bt -> data && bt -> data <= 9)
		printf("%d ", bt -> data);
	else
		printf("%c ", bt -> data);
}
