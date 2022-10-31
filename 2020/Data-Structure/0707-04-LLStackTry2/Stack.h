#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
} Node;

typedef struct _Stack {
	Node * top;
} Stack;

void init_stack(Stack * pstack);
void push(Stack * pstack, Data data);
Data pop(Stack * pstack);
Data peek(Stack * pstack);
BOOL is_empty(Stack * pstack);

#endif
