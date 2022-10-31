#ifndef __STACK_H__
#define __STACK_H__

#include "BTree.h"

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef BTreeNode * SData;

typedef struct _Node {
	SData data;
	struct _Node * next;
} Node;

typedef struct _Stack {
	Node * top;
} Stack;

void  init_stack(Stack * pstack);
void  push      (Stack * pstack, SData data);
SData pop       (Stack * pstack);
SData peek      (Stack * pstack);
BOOL  is_empty  (Stack * pstack);

#endif
