#include <stdio.h>
#include "Heap.h"

int main(void)
{
	Heap heap;
	int i;
	init_heap(&heap);
	
	for (i = 0; i < 26; i++)
		insert_heap(&heap, 'A' + i, i + 1);
	
	while (!is_empty(&heap))
		printf("%c ", delete_heap(&heap));
	
	return 0;
}
