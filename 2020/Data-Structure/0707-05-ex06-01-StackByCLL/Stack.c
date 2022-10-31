#include "Stack.h"

void init_stack(Stack * pstack)
{
	ListInit(pstack);
}

void push(Stack *pstack, LData data)
{
	LInsertFront(pstack, data);
}

LData pop(Stack * pstack)
{
	LData data;
	
	if (LCount(pstack) == 0)
		return;
		
	LFirst(pstack, &data);
	LRemove(pstack);
	
	return data;
}

LData peek(Stack * pstack)
{
	LData data;
	
	if (LCount(pstack) == 0)
		return;
		
	LFirst(pstack, &data);
	return data;
}

int is_empty(Stack * pstack)
{
	if (LCount(pstack) == 0)
		return TRUE;
		
	else
		return FALSE;
}
