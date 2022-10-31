#ifndef __HEAP_H__
#define __HEAP_H__

typedef int BOOL;
#define TRUE  1
#define FALSE 0

typedef char HData;
typedef int  Priority;

typedef struct _HeapElement {
	Priority pr;
	HData    data;
} HeapElement;

#define HEAP_LEN 100

typedef struct _Heap {
	int         num_data;
	HeapElement heap_arr[HEAP_LEN];
} Heap;

void init_heap(Heap * ph);
BOOL is_empty (Heap * ph);

void  insert_heap(Heap * hp, HData data, Priority pr);
HData delete_heap(Heap * hp);

#endif
