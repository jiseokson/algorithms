#include <stdio.h>
#include "CQueue.h"

int main(void)
{
	Queue q;
	
	init_queue(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	
	while (!empty(&q))
		printf("%d ", dequeue(&q));
	
	return 0;
}
