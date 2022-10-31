#ifndef __HEAP_H__
#define __HEAP_H__

typedef int Bool;
#define TRUE  1
#define FALSE 0

typedef char HData;
typedef Bool PriorityCompareFunction(HData d1, HData d2);

#define HEAP_LEN 64

typedef struct _Heap {
	PriorityCompareFunction * comparePriority;
	int                       numData;
	HData                     heapDatas[HEAP_LEN + 1];
} Heap;

       void initHeap(Heap * heap, PriorityCompareFunction comparePriority);
inline Bool isEmpty (Heap * heap);

void  insertHeap(Heap * heap, HData newData);
HData deleteHeap(Heap * heap);

#endif
