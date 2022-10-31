#include <stdio.h>
#include "LinkedList.h"

BOOL ord(Data d1, Data d2)
{
	if (d1 <= d2)
		return TRUE;
		
	else
		return FALSE;
}

int main(void)
{
	LinkedList l;
	Data d;
	
	init_list(&l);
	set_sort(&l, ord);
	
	insert(&l, 1);
	insert(&l, 2);
	insert(&l, 3);
	
	printf("현재 저장된 데이터 수 : %d\n", count(&l));
	
	if (search_first(&l, &d)) {
		printf("%d ", d);
		
		while (search_next(&l, &d))
			printf("%d ", d);
	}
	
	putchar('\n');
	
	if (search_first(&l, &d)) {
		if (d == 1) del(&l);
		
		while (search_next(&l, &d))
			if (d == 1) del(&l);
	}
	
	printf("현재 저장된 데이터 수 : %d\n", count(&l));
	
	if (search_first(&l, &d)) {
		printf("%d ", d);
		
		while (search_next(&l, &d))
			printf("%d ", d);
	}
	
	putchar('\n');
	
	if (search_first(&l, &d)) {
		del(&l);
		
		while (search_next(&l, &d))
			del(&l);
	}
	
	return 0;
}
