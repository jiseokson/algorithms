#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
} Node;

typedef struct _LinkedList {
	Node * head;
	Node * cur;
	Node * before;
	int num_data;
	BOOL (* comp)(Data d1, Data d2);
} LinkedList;

void init_list(LinkedList * plist);
void set_sort(LinkedList * plist, BOOL (* comp)(Data d1, Data d2));

void insert(LinkedList * plist, Data data);

BOOL search_first(LinkedList * plist, Data * pdata);
BOOL search_next(LinkedList * plist, Data * pdata);
int count(LinkedList * plist);

Data del(LinkedList * plist);

#endif
