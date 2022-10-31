#ifndef _STACK_H__
#define _STACK_H__


#include "Graph.h"

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int SData;

#define STACK_LEN 100

typedef struct _ArrayStack {
	SData arr[STACK_LEN];
	int top;
} Stack;

void  initStack(Stack * pstack);
void  push     (Stack * pstack, SData data);
SData pop      (Stack * pstack);
SData peek     (Stack * pstack);
BOOL  isEmpty  (Stack * pstack);

#endif
