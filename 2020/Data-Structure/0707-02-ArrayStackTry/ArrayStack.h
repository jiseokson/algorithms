#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

#define STACK_LEN 100

typedef struct _ArrayStack {
	Data arr[STACK_LEN];
	int top;
} Stack;

void init_stack(Stack * pstack);
void push(Stack * pstack, Data data);
Data pop(Stack * pstack);
Data peek(Stack * pstack);
BOOL is_empty(Stack * pstack);

#endif
