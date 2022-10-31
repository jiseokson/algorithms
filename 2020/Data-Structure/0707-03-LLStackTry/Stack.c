#include <stdlib.h>
#include "Stack.h"

void init_stack(Stack * pstack)
{
	pstack -> top = (Node *)malloc(sizeof(Node));
	pstack -> top -> next = NULL;
}

void push(Stack * pstack, Data data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = pstack -> top -> next;
	pstack -> top -> next = new_node;
}

Data pop(Stack * pstack)
{
	Node * pop_node = pstack -> top -> next;
	Data pop_data = pop_node -> data;
	
	pstack -> top -> next = pstack -> top -> next -> next;
	
	free(pop_node);
	
	return pop_data;
}

Data peek(Stack * pstack)
{
	return pstack -> top -> next -> data;
}

BOOL is_empty(Stack * pstack)
{
	if (pstack -> top -> next == NULL)
		return TRUE;
		
	else
		return FALSE;
}
