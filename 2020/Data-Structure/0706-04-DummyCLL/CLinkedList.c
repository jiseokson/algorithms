#include <stdlib.h>
#include "CLinkedList.h"

void init_list(CLinkedList * plist)
{
	plist -> tail = (Node *)malloc(sizeof(Node));
	plist -> tail -> next = plist -> tail;
	
	plist -> cur = NULL;
	plist -> before = NULL;
	plist -> num_data = 0;
	plist -> comp = NULL;
}

void insert(CLinkedList * plist, Data data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	
	new_node -> data = data;
	new_node -> next = plist -> tail -> next;
	plist -> tail -> next = new_node;
	
	plist -> tail = new_node;
	
	plist -> num_data++;
}

BOOL first(CLinkedList * plist, Data * pdata)
{
	if (plist -> num_data == 0)
		return FALSE;
		
	plist -> before = plist -> tail -> next;
	plist -> cur = plist -> before -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

BOOL next(CLinkedList * plist, Data * pdata)
{
	if (plist -> num_data == 0)
		return FALSE;
		
	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;
	
	if (plist -> cur == plist -> tail -> next) {
		plist -> before = plist -> cur;
		plist -> cur = plist -> cur -> next;
	}
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

Data del(CLinkedList * plist)
{
	Node * del_node = plist -> cur;
	Data * del_data = del_node -> data;
	
	if (plist -> num_data == 0)
		return NULL;
		
	if (plist -> cur -> next == plist -> tail -> next || plist -> before -> next == plist -> tail -> next)
}

int count(CLinkedList * plist);
