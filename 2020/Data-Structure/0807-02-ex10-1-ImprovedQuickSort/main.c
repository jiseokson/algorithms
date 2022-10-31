#include <stdio.h>

inline void swap(int arr[], int index1, int index2)
{
	int temp    = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int partition(int arr[], int left, int right)
{
	int low  = left + 1;
	int high = right;
	
	int pivotNominees[3] = {left, (left + right) / 2, right};
	int i, j;
	
	///*
	// select pivot
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2 - i; j++) {
			if (arr[pivotNominees[j]] > arr[pivotNominees[j + 1]]) {
				int temp             = pivotNominees[j + 1];
				pivotNominees[j + 1] = pivotNominees[j];
				pivotNominees[j]     = temp;
			}
		}
	}
	swap(arr, left, pivotNominees[1]);
	//*/
	
	int pivot     = left;
	int pivotData = arr[pivot];
	
	while (low <= high) {
		while (! (pivotData <= arr[low]))
			low++;
		
		while (! (arr[high] <= pivotData))
			high--;
		
		if (low <= high)
			swap(arr, low, high);
	}
	
	/*
	//int i;
	printf("pivotData : %d\n", arr[pivot]);
	for(i = left + 1; i <= right; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
	*/
	
	swap(arr, pivot, high);
	return high;
}

void quickSort(int arr[], int left, int right)
{
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int arr[] = {5, 7, 10, 2, 3, 4, 14, 9, 8, 1, 6, 15, 11, 13, 12};
	int len   = sizeof(arr) / sizeof(int);
	int i;
	
	quickSort(arr, 0, len - 1);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
