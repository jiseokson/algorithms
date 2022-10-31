#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
} Node;

typedef struct _CCL {
	Node * tail;
	Node * cur;
	Node * before;
	int num_data;
	BOOL (* comp)(Data d1, Data d2);
} CLinkedList;

void init_list(CLinkedList * plist);
void insert(CLinkedList * plist, Data data);
BOOL first(CLinkedList * plist, Data * pdata);
BOOL next(CLinkedList * plist, Data * pdata);
Data del(CLinkedList * plist);
int count(CLinkedList * plist);

#endif
