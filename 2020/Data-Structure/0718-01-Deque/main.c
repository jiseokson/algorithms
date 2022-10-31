#include <stdio.h>
#include "Deque.h"

int main(void)
{
	Deque dq;
	
	init_deque(&dq);
	insert_front(&dq, 3);
	insert_front(&dq, 2);
	insert_front(&dq, 1);
	insert_rear(&dq, 4);
	insert_rear(&dq, 5);
	insert_rear(&dq, 6);
	
	while (!is_empty(&dq))
		printf("%d ", remove_front(&dq));
		
	return 0;
}
