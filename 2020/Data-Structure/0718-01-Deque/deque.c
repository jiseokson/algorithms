#include <stdlib.h>
#include "Deque.h"

void init_deque(Deque * pdq)
{
	pdq -> front = (Node *)malloc(sizeof(Node));
	pdq -> rear  = (Node *)malloc(sizeof(Node));
	
	pdq -> front -> next    = pdq -> rear;
	pdq -> rear -> previous = pdq -> front;
}

BOOL is_empty(Deque * pdq)
{
	if (pdq -> front -> next == pdq -> rear)
		return TRUE;
		
	else
		return FALSE;
}

void insert_front(Deque * pdq, Data data)
{
	Node * new_node  = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	new_node -> next     = pdq -> front -> next;
	new_node -> previous = pdq -> front;
	
	new_node -> next -> previous = new_node;
	new_node -> previous -> next = new_node;
}

void insert_rear(Deque * pdq, Data data)
{
	Node * new_node  = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	new_node -> next     = pdq -> rear;
	new_node -> previous = pdq -> rear -> previous;
	
	new_node -> next -> previous = new_node;
	new_node -> previous -> next = new_node;
}

Data remove_front(Deque * pdq)
{
	if (is_empty(pdq))
		return;
		
	Node * del_node = pdq -> front -> next;
	Data del_data   = del_node -> data;
	
	del_node -> next -> previous = del_node -> previous;
	del_node -> previous -> next = del_node -> next;
	
	free(del_node);
	return del_data;
}

Data remove_rear(Deque * pdq)
{
	if (is_empty(pdq))
		return;
		
	Node * del_node = pdq -> rear -> previous;
	Data del_data   = del_node -> data;
	
	del_node -> next -> previous = del_node -> previous;
	del_node -> previous -> next = del_node -> next;
	
	free(del_node);
	return del_data;
}

Data get_front(Deque * pdq)
{
	if (is_empty(pdq))
		return;
		
	return pdq -> front -> next -> data;
}

Data get_rear(Deque * pdq)
{
	if (is_empty(pdq))
		return;
		
	return pdq -> rear -> previous -> data;
}
