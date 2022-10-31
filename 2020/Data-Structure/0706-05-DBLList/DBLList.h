#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef int Data;

typedef struct _Node {
	Data data;
	struct _Node * next;
	struct _Node * prev;
} Node;

typedef struct _DBLList {
	Node * head;
	Node * cur;
	int num_data;
} DBLList;

void init_list(DBLList * pl);
void insert(DBLList * pl, Data d);

BOOL first(DBLList * pl, Data * pd);
BOOL next(DBLList * pl, Data * pd);
BOOL previous(DBLList * pl, Data * pd);

int count(DBLList * pl);

#endif
