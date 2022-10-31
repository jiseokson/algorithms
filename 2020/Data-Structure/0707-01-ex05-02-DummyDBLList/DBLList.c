#include <stdlib.h>
#include "DBLList.h"

void init_list(DBLList * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> tail = (Node *)malloc(sizeof(Node));
	
	plist -> head -> prev = NULL;
	plist -> head -> next = plist -> tail;
	
	plist -> tail -> next = NULL;
	plist -> tail -> prev = plist -> head;
	
	plist -> num_data = 0;
}

void insert_head(DBLList * plist, Data data);

void insert_tail(DBLList * plist, Data data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	new_node -> next = plist -> tail;
	new_node -> prev = plist -> tail -> prev;
	
	plist -> tail -> prev -> next = new_node;
	plist -> tail -> prev = new_node;
	
	plist -> num_data++;
}

BOOL first(DBLList * plist, Data * pdata)
{
	if (plist -> num_data == 0)
		return FALSE;
		
	plist -> cur = plist -> head -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

BOOL next(DBLList * plist, Data * pdata)
{
	if (plist -> num_data == 0)
		return FALSE;
		
	if (plist -> cur -> next == plist -> tail)
		return FALSE;
		
	plist -> cur = plist -> cur -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

BOOL previous(DBLList * plist, Data * pdata)
{
	if (plist -> num_data == 0)
		return FALSE;
		
	if (plist -> cur -> prev == plist -> head)
		return FALSE;
		
	plist -> cur = plist -> cur -> prev;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

Data del(DBLList * plist)
{
	Node * del_node = plist -> cur;
	Data del_data = del_node -> data;
	
	plist -> cur -> prev -> next = plist -> cur -> next;
	plist -> cur -> next -> prev = plist -> cur -> prev;
	
	plist -> cur = plist -> cur -> prev; // 
	
	free(del_node);
	plist -> num_data--;
	
	return del_data;
}

int count(DBLList * plist)
{
	return plist -> num_data;
}
