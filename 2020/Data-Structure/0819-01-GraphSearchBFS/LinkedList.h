#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define TRUE  1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node * next;
} Node;

typedef struct _LinkedList {
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
} LinkedList;

typedef LinkedList List;

void initList(List * plist);

void insertList(List * plist, LData data);

int searchFirst(List * plist, LData * pdata);
int searchNext(List * plist, LData * pdata);

LData removeList(List * plist);

int countList(List * plist);

#endif
