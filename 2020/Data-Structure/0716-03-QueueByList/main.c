#include <stdio.h>
#include "LQueue.h"

int main(void)
{
	Queue q;
	
	init_queue(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	
	while (!is_empty(&q))
		printf("%d ", dequeue(&q));
	
	return 0;
}
