#include "ArrayStack.h"

void init_stack(Stack * pstack)
{
	pstack -> top = -1;
}

void push(Stack * pstack, Data data)
{
	if (pstack -> top == STACK_LEN - 1)
		return;
		
	pstack -> top++;
	pstack -> arr[pstack -> top] = data;
}

Data pop(Stack * pstack)
{
	return pstack -> arr[pstack -> top--];
}

Data peek(Stack * pstack)
{
	return pstack -> arr[pstack -> top];
}

BOOL is_empty(Stack * pstack)
{
	if (pstack -> top == -1)
		return TRUE;
		
	else
		return FALSE;
}
