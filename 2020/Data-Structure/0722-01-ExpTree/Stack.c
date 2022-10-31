#include <stdlib.h>
#include "Stack.h"

void init_stack(Stack * pstack)
{
	pstack -> top = NULL;
}

void push(Stack * pstack, SData data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = pstack -> top;
	pstack -> top = new_node;
}

SData pop(Stack * pstack)
{
	Node * pop_node = pstack -> top;
	SData pop_data = pop_node -> data;
	pstack -> top = pstack -> top -> next;
	free(pop_node);
	return pop_data;
}

SData peek(Stack * pstack)
{
	return pstack -> top -> data;
}

BOOL is_empty(Stack * pstack)
{
	if (pstack -> top == NULL)
		return TRUE;
		
	else
		return FALSE;
}
