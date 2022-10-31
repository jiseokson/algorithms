#include "CQueue.h"

void init_queue(Queue * pq)
{
	pq -> front = 0;
	pq -> rear  = 0;
}

BOOL empty(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return TRUE;
		
	else
		return FALSE;
}

void enqueue(Queue * pq, Data data)
{
	if (pq -> front == (pq -> rear + 1) % QUEUE_LEN)
		return;
		
	pq -> rear = (pq -> rear + 1) % QUEUE_LEN;
	pq -> qArr[pq -> rear] = data;
}

Data dequeue(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return;
		
	pq -> front = (pq -> front + 1) % QUEUE_LEN;
	return pq -> qArr[pq -> front];
}

Data peek(Queue * pq)
{
	return pq -> qArr[(pq -> front + 1) % QUEUE_LEN];
}
