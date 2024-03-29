#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List * plist)
{
	plist -> head = (Node *)malloc(sizeof(Node));
	plist -> head -> next = NULL;
	plist -> comp = NULL;
	plist -> numOfData = 0;
}

void setSortRule(List  * plist, int (* comp)(LData d1, LData d2))
{
	plist -> comp = comp;
}

void insertList(List * plist, LData data)
{
	// 정렬기준이 없는 경우 
	if (plist -> comp == NULL) {
		Node * new_node = (Node *)malloc(sizeof(Node));
		new_node -> data = data;
		
		new_node -> next = plist -> head -> next;
		plist -> head -> next = new_node;
		
		plist -> numOfData++;
	}
	
	// 정렬기준이 있는 경우 
	else {
		//
	}
}

int searchFirst(List * plist, LData * pdata)
{
	if (plist -> head -> next == NULL)
		return FALSE;
		
	plist -> before = plist -> head;
	plist -> cur = plist -> head -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

int searchNext(List * plist, LData * pdata)
{
	if (plist -> cur -> next == NULL)
		return FALSE;
		
	// 삭제시 일관성있는 실행을 위해 cur을 before에 대입
	plist -> before = plist -> cur; //plist -> before -> next;
	plist -> cur = plist -> cur -> next;
	
	*pdata = plist -> cur -> data;
	
	return TRUE;
}

LData removeList(List * plist)
{
	Node * del_node = plist -> cur;
	LData del_data = del_node -> data;
	
	plist -> before -> next = plist -> cur -> next;
	plist -> cur = plist -> before;
	
	free(del_node);
	plist -> numOfData--;
	
	return del_data;
}

int countList(List * plist)
{
	return plist -> numOfData;
}
