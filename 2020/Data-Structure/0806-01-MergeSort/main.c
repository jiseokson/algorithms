#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _mergeTwoArray(int mixedArr[], int left, int mid, int right, int tempArr[])
{
	int tempIndex  = left;
	int frontIndex = left;
	int rearIndex  = mid + 1;
	int i;
	
	while ((frontIndex <= mid) && (rearIndex <= right)) {
		if (mixedArr[frontIndex] <= mixedArr[rearIndex])
			tempArr[tempIndex] = mixedArr[frontIndex++];
		else
			tempArr[tempIndex] = mixedArr[rearIndex++];
			
		tempIndex++;
	}
	
	while (frontIndex <= mid) {
		tempArr[tempIndex] = mixedArr[frontIndex++];
		tempIndex++;
	}
	
	while (rearIndex <= right) {
		tempArr[tempIndex] = mixedArr[rearIndex++];
		tempIndex++;
	}
	
	for (i = left; i <= right; i++)
		mixedArr[i] = tempArr[i];
}

void _mergeSort(int mixedArr[], int left, int right, int tempArr[])
{
	/*int i;
	printf("call : %d %d\n", left, right);*/
	
	if (left < right) {
		int mid = (left + right) / 2;
		
		_mergeSort(mixedArr, left, mid, tempArr);      // left <= i <= mid
		_mergeSort(mixedArr, mid + 1, right, tempArr); // mid < i <= right
		
		_mergeTwoArray(mixedArr, left, mid, right, tempArr);
		
		/*printf("done : %d %d\n", left, right);
		printf(">> ");
		for (i = left; i <= right; i++)
			printf("%d ", mixedArr[i]);
		putchar('\n');*/
	}
}

inline void mergeSort(int mixedArr[], int len)
{
	int * tempArr = (int *)malloc(len * sizeof(int));
	int   i;
	
	_mergeSort(mixedArr, 0, len - 1, tempArr);
	
	free(tempArr);
}

int main(void)
{
	srand(time(NULL));
	
	int arr[] = {
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100,
		rand() % 100
	};
	int len   = sizeof(arr) / sizeof(int);
	int i;
	
	mergeSort(arr, len);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
		
	return 0;
}
