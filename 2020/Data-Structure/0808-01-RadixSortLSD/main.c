#include <stdio.h>
#include "LQueue.h"

void radixSort(int arr[], int len)
{
	Queue radixQueue[10];
	int i, j, k, r = 1;
	
	for (i = 0; i < 10; i++)
		init_queue(&radixQueue[i]);
		
	for (i = 0; i < 3; i++) {
		for (j = 0; j < len; j++) {
			int radix = arr[j] / r % 10;
			enqueue(&radixQueue[radix], arr[j]);
		}
		
		int index = 0;
		for (k = 0; k < 10; k++) {
			while (!is_empty(&radixQueue[k])) {
				arr[index++] = dequeue(&radixQueue[k]);
				//index++;
			}
		}
		
		r *= 10;
	}
}

int main(void)
{
	int arr[] = {122, 224, 232, 134, 567, 385, 704};
	int len   = sizeof(arr) / sizeof(int);
	int i;
	
	radixSort(arr, len);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
