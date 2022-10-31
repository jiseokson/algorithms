#include <stdlib.h>
#include "LinkedList.h"

void init_list(LinkedList * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> head -> next = NULL;
	plist -> num_data = 0;
	plist -> comp = NULL;
}

void set_sort(LinkedList * plist, BOOL (* comp)(Data d1, Data d2))
{
	plist -> comp = comp;
}

void insert(LinkedList * plist, Data data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next = NULL;
	
	if (plist -> comp == NULL) {
		new_node -> next = plist -> head -> next;
		plist -> head -> next = new_node;
	}
	
	else {
		Node * pred = plist -> head;
		
		while (pred -> next != NULL && plist -> comp(data, pred -> next -> data) != TRUE)
			pred = pred -> next;
			
		new_node -> next = pred -> next;
		pred -> next = new_node;
	}
	
	plist -> num_data++;
}

BOOL search_first(LinkedList * plist, Data * pdata)
{
	if (plist -> head -> next == NULL)
		return FALSE;
		
	plist -> cur = plist -> head -> next;
	plist -> before = plist -> head;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

BOOL search_next(LinkedList * plist, Data * pdata)
{
	if (plist -> cur -> next == NULL)
		return FALSE;
		
	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

int count(LinkedList * plist)
{
	return plist -> num_data;
}

Data del(LinkedList * plist)
{
	Node * del_node = plist -> cur;
	Data del_data = del_node -> data;
	
	plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;
	
	free(del_node);
	plist -> num_data--;
	
	return del_data;
}
