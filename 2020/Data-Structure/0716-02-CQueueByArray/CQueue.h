#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;
#define QUEUE_LEN 100

typedef struct _Queue {
	int front;
	int rear;
	Data qArr[QUEUE_LEN + 1];
} Queue;

void init_queue(Queue * pq);
BOOL empty(Queue * pq);
void enqueue(Queue * pq, Data data);
Data dequeue(Queue * pq);
Data peek(Queue * pq);

#endif
