#ifndef __DBL_LIST_H__
#define __DBL_LIST_H__

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
	Node * tail;
	Node * cur;
	int num_data;
} DBLList;

void init_list(DBLList * plist);

void insert_head(DBLList * plist, Data data);
void insert_tail(DBLList * plist, Data data);

BOOL first(DBLList * plist, Data * pdata);
BOOL next(DBLList * plist, Data * pdata);
BOOL previous(DBLList * plist, Data * pdata);

Data del(DBLList * plist);

int count(DBLList * plist);

#endif
