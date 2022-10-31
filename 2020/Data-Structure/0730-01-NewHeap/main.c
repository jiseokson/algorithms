#include <stdio.h>
#include "Heap.h"

Bool ord(HData d1, HData d2)
{
	if (d1 < d2)
		return TRUE;
	else
		return FALSE;
}

void showHeap(Heap heap)
{
	HData * heapDatas = heap.heapDatas;
	int     numData   = heap.numData;
	
	int d, depth = 0;
	int blankSpacing = 0;
	int nodesInLevel = 1;
	int index        = 1;
	int i, j, k;
	
	printf("Data #%d\n", numData);
	
	// compute 'depth' & 'blank spacing'
	for (d = 1; d * 2 <= numData; d *= 2) {
		depth++;
		blankSpacing = 2 * blankSpacing + 1;
	}
		
	// print nodes from level 0 to 'depth - 1'
	for (i = 0; i < depth; i++) {
		for (j = 0; j < nodesInLevel; j++) {
			for (k = 0; k < blankSpacing / 2; k++)
				putchar(' ');
			for (; k < blankSpacing; k++)
				putchar('_');
				
			printf("%c", heapDatas[index++]);
			
			for (k = 0; k < blankSpacing / 2 + 1; k++)
				putchar('_');
			for (; k < blankSpacing + 1; k++)
				putchar(' ');
		}
		
		putchar('\n');
		
		nodesInLevel *= 2;
		blankSpacing /= 2;
	}
	
	// print remain nodes
	while (index <= numData)
		printf("%c ", heapDatas[index++]);
		
	printf("\n\n");
}

int main(void)
{
	Heap heap;
	char c;	
	
	initHeap(&heap, ord);
	
	for (c = 'A'; c <= 'z'; c++)
		insertHeap(&heap, c);
	
	printf("Initial state\n");
	showHeap(heap);
	
	while (!isEmpty(&heap)) {
		printf("Delete : <%c>\n", deleteHeap(&heap));
		showHeap(heap);
	}
	
	return 0;
}
