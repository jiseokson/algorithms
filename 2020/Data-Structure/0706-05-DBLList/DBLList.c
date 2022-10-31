#include <stdlib.h>
#include "DBLList.h"

void init_list(DBLList * pl)
{
	pl -> head = NULL;
	pl -> num_data = 0;
}

void insert(DBLList * pl, Data d)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node -> data = d;
	new_node -> next = pl -> head;
	new_node -> prev = NULL;
	
	if (pl -> head != NULL)
		pl -> head -> prev = new_node;
		
	pl -> head = new_node;
	
	pl -> num_data++;
	/*
	if (pl -> num_data == 0) {
		new_node -> next = NULL;
		pl -> head = new_node;
	}
	
	else {
		//
	}
	*/
}

BOOL first(DBLList * pl, Data * pd);
BOOL next(DBLList * pl, Data * pd);
BOOL previous(DBLList * pl, Data * pd);

int count(DBLList * pl);
