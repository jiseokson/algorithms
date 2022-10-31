#include <stdio.h>
#include "ArrayStack.h"

int main(void)
{
	Stack stack;
	
	init_stack(&stack);
	
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	
	while (!is_empty(&stack))
		printf("%d ", pop(&stack));
		
	return 0;
}
