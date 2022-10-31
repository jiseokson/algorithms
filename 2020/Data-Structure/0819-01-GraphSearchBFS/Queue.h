#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int QData;
#define QUEUE_LEN 100

typedef struct _Queue {
	int  front;
	int  rear;
	QData qArr[QUEUE_LEN + 1];
} Queue;

void initQueue(Queue * pq);
BOOL isEmpty(Queue * pq);
void enqueue(Queue * pq, QData data);
QData dequeue(Queue * pq);
QData peek(Queue * pq);

#endif
