#ifndef __STACK_H__
#define __STACK_H__

#include "CLinkedList.h"

typedef List Stack;

void init_stack(Stack * pstack);
void push(Stack * pstack, LData data);
LData pop(Stack * pstack);
LData peek(Stack * pstack);
int is_empty(Stack * pstack);

#endif
