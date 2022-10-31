#ifndef __L_QUEUE_H__
#define __L_QUEUE_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
} Node;

typedef struct _Queue {
	Node * front;
	Node * rear;
} Queue;

void init_queue(Queue * pq);
BOOL is_empty  (Queue * pq);

void enqueue(Queue * pq, Data data);
Data dequeue(Queue * pq);
Data peek   (Queue * pq);

#endif
