#include <stdlib.h>
#include "LQueue.h"

void init_queue(Queue * pq)
{
	Node * dummy_node  = (Node *)malloc(sizeof(Node));
	dummy_node -> next = NULL;
	
	pq -> front = dummy_node;
	pq -> rear  = dummy_node;
}

BOOL is_empty(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return TRUE;
		
	else
		return FALSE;
}

void enqueue(Queue * pq, Data data)
{
	Node * new_node  = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	
	pq -> rear -> next = new_node;
	pq -> rear         = new_node;
}

Data dequeue(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return;
	
	Node * del_node = pq -> front;
	pq -> front     = pq -> front -> next;
	
	free(del_node);
	return pq -> front -> data;
}

Data peek(Queue * pq)
{
	if (pq -> front == pq -> rear)
		return;
		
	return pq -> front -> next -> data;
}
