#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> head -> next = NULL;
	plist -> comp = NULL;
	plist -> numOfData = 0;
}

void SetSortRule(List  * plist, int (* comp)(LData d1, LData d2))
{
	plist -> comp = comp;
}

void LInsert(List * plist, LData data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = data;
	
	// 정렬기준이 없는 경우 
	if (plist -> comp == NULL) {
		new_node -> next = plist -> head -> next;
		plist -> head -> next = new_node;
	}
	
	// 정렬기준이 있는 경우 
	else {
		Node * pred = plist -> head;
		
		while (pred -> next != NULL && plist -> comp(data, pred -> next -> data) != TRUE)
			pred = pred -> next;
			
		new_node -> next = pred -> next;
		pred -> next = new_node;
	}
	
	plist -> numOfData++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist -> head -> next == NULL)
		return FALSE;
		
	plist -> before = plist -> head;
	plist -> cur = plist -> head -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist -> cur -> next == NULL)
		return FALSE;
		
	// 삭제시 일관성있는 실행을 위해 cur을 before에 대입
	plist -> before = plist -> cur; //plist -> before -> next;
	plist -> cur = plist -> cur -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * del_node = plist -> cur;
	LData del_data = del_node -> data;
	
	plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;
	
	free(del_node);
	plist -> numOfData--;
	
	return del_data;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}
