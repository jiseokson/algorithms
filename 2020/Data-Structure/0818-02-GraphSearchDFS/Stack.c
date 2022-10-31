#include "Stack.h"

void initStack(Stack * pstack)
{
	pstack -> top = -1;
}

void push(Stack * pstack, SData data)
{
	if (pstack -> top == STACK_LEN - 1)
		return;
		
	pstack -> top++;
	pstack -> arr[pstack -> top] = data;
}

SData pop(Stack * pstack)
{
	return pstack -> arr[pstack -> top--];
}

SData peek(Stack * pstack)
{
	return pstack -> arr[pstack -> top];
}

BOOL isEmpty(Stack * pstack)
{
	if (pstack -> top == -1)
		return TRUE;
		
	else
		return FALSE;
}
