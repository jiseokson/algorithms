#include "Queue.h"

void initQueue(Queue * pq)
{
	pq -> front = 0;
	pq -> rear  = 0;
}

BOOL isEmpty(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return TRUE;
		
	else
		return FALSE;
}

void enqueue(Queue * pq, QData data)
{
	if (pq -> front == (pq -> rear + 1) % QUEUE_LEN)
		return;
		
	pq -> rear = (pq -> rear + 1) % QUEUE_LEN;
	pq -> qArr[pq -> rear] = data;
}

QData dequeue(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return;
		
	pq -> front = (pq -> front + 1) % QUEUE_LEN;
	return pq -> qArr[pq -> front];
}

QData peek(Queue * pq)
{
	return pq -> qArr[(pq -> front + 1) % QUEUE_LEN];
}
