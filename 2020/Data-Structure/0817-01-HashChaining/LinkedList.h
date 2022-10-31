#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Slot.h"

#define TRUE  1
#define FALSE 0

typedef Slot LData;

typedef struct _node {
	LData data;
	struct _node * next;
} Node;

typedef struct _LinkedList {
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int (* comp)(LData d1, LData d2);
	
	enum  SlotStatus status;
} LinkedList;

typedef LinkedList List;

void initList(List * plist);
void setSortRule(List * plist, int (* comp)(LData d1, LData d2));

void insertList(List * plist, LData data);

int searchFirst(List * plist, LData * pdata);
int searchNext(List * plist, LData * pdata);

LData removeList(List * plist);

int countList(List * plist);

#endif
