#include "Heap.h"

void initHeap(Heap * heap, PriorityCompareFunction comparePriority)
{
	heap -> comparePriority = comparePriority;
	heap -> numData         = 0;
}

inline Bool isEmpty(Heap * heap)
{
	if (heap -> numData == 0)
		return TRUE;
	else
		return FALSE;
}


inline int getParentIndex(int index)
{
	return index / 2;
}

inline int getLeftChildIndex(int index)
{
	return 2 * index;
}

inline int getRightChildIndex(int index)
{
	return 2 * index + 1;
}

int getHighPriorityChildIndex(Heap * heap, int parentIndex)
{
	PriorityCompareFunction * comparePriority = heap -> comparePriority;
	HData                   * heapDatas       = heap -> heapDatas;
	int                       numData         = heap -> numData;
	
	int leftChildIndex  = getLeftChildIndex(parentIndex);
	int rightChildIndex = getRightChildIndex(parentIndex);
	
	if (leftChildIndex > numData)
		return 0;
	else if (leftChildIndex == numData)
		return leftChildIndex;
		
	else if (comparePriority(heapDatas[leftChildIndex], heapDatas[rightChildIndex]))
		return leftChildIndex;
	else
		return rightChildIndex;
}


void insertHeap(Heap * heap, HData newData)
{
	PriorityCompareFunction * comparePriority = heap -> comparePriority;
	HData                   * heapDatas       = heap -> heapDatas;
	
	int parentIndex, childIndex = heap -> numData + 1;
	
	while (childIndex != 1) {
		parentIndex = getParentIndex(childIndex);
		
		if (comparePriority(heapDatas[parentIndex], newData))
			break;
		
		heapDatas[childIndex] = heapDatas[parentIndex];
		childIndex            = parentIndex;
	}
	
	heapDatas[childIndex] = newData;
	heap -> numData++;
}

HData deleteHeap(Heap * heap)
{
	PriorityCompareFunction * comparePriority = heap -> comparePriority;
	HData                   * heapDatas       = heap -> heapDatas;
	
	HData deletedData = heap -> heapDatas[1];
	HData lastData    = heap -> heapDatas[heap -> numData];
	int   parentIndex = 1, childIndex;
	
	while (childIndex = getHighPriorityChildIndex(heap, parentIndex)) {
		if (comparePriority(lastData, heapDatas[childIndex]))
			break;
			
		heapDatas[parentIndex] = heapDatas[childIndex];
		parentIndex            = childIndex;
	}
	
	heapDatas[parentIndex] = lastData;
	heap -> numData--;
	
	return deletedData;
}
