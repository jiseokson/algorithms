#include <stdio.h>
#include "DBLList.h"

int main(void)
{
	DBLList list;
	int data;
	
	init_list(&list);
	insert(&list, 1);
	insert(&list, 2);
	insert(&list, 3);
	insert(&list, 4);
	insert(&list, 5);
	insert(&list, 6);
	insert(&list, 7);
	insert(&list, 8);
	
	if (first(&list, &data)) {
		while (next(&list, &data))
			printf("%d ", data);
			
		while (previous(&list, &data))
			printf("%d ", data);
	}
	
	return 0;
}
