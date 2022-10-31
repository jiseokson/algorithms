#include <stdio.h>
#include "DBLList.h"

int main(void)
{
	DBLList list;
	int data;
	
	init_list(&list);
	insert_tail(&list, 1);
	insert_tail(&list, 2);
	insert_tail(&list, 3);
	insert_tail(&list, 4);
	insert_tail(&list, 5);
	
	if (first(&list, &data)) {
		printf("%d ", data);
		
		while (next(&list, &data))
			printf("%d ", data);
		
		while (previous(&list, &data))
			printf("%d ", data);
	}
	
	return 0;
}
