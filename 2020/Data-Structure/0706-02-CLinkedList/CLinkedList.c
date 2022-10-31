#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist -> tail = NULL;
	plist -> cur = NULL;
	plist -> before = NULL;
	plist -> numOfData = 0;
}

void LInsert(List * plist, LData data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	if (plist -> tail == NULL) {
		plist -> tail = new_node;
		new_node -> next = new_node;
	}
	
	else {
		new_node -> next = plist -> tail -> next;
		plist -> tail -> next = new_node;
		plist -> tail = new_node; // 유일하게 다른 부분 
	}
	
	plist -> numOfData++;
}

void LInsertFront(List * plist, LData data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	if (plist -> tail == NULL) {
		plist -> tail = new_node;
		new_node -> next = new_node;
	}
	
	else {
		new_node -> next = plist -> tail -> next;
		plist -> tail -> next = new_node;
	}
	
	plist -> numOfData++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist -> tail == NULL)
		return FALSE;
		
	plist -> before = plist -> tail;
	plist -> cur = plist -> tail -> next;
	
	*pdata = plist -> cur -> data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist -> tail == NULL)
		return FALSE;
		
	plist -> before = plist -> cur;
	plist -> cur = plist -> cur -> next;
	
	*pdata = plist -> cur -> data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * del_node = plist -> cur;
	LData del_data = del_node -> data;
	
	if (del_node == plist -> tail) {
		if (plist -> tail == plist -> tail -> next) // plist -> numOfData == 1
			plist -> tail = NULL;
			
		else
			plist -> tail = plist -> before;
	}
	
	else {
		plist -> before -> next = plist -> cur -> next;
		plist -> cur = plist -> before;
	}
	
	free(del_node);
	plist -> numOfData--;
	
	return del_data;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}
