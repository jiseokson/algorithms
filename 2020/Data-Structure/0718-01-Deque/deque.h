#ifndef __DEQUE_H__
#define __DEQUE_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
	struct _Node * previous;
} Node;

typedef struct _Deque {
	Node * front;
	Node * rear;
} Deque;

void init_deque(Deque * pdq);
BOOL is_empty  (Deque * pdq);

void insert_front(Deque * pdq, Data data);
void insert_rear (Deque * pdq, Data data);

Data remove_front(Deque * pdq);
Data remove_rear (Deque * pdq);

Data get_front(Deque * pdq);
Data get_rear (Deque * pdq);

#endif
