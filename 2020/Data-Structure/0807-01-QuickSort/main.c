#include <stdio.h>

inline void swap(int arr[], int index1, int index2)
{
	int temp    = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot     = left;
	int pivotData = arr[pivot];
	int low       = left + 1;
	int high      = right;
	
	while (low <= high) {
		while (! (pivotData <= arr[low]))
			low++;
			
		while (! (arr[high] <= pivotData))
			high--;
			
		if (low <= high)
			swap(arr, low, high);
	}
	
	int i;
	printf("pivotData : %d\n", arr[pivot]);
	for(i = left + 1; i <= right; i++)
		printf("%d ", arr[i]);
	putchar('\n');
	
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
	int arr[] = {3, 6, 1, 8, 9, 5, 7, 2, 4};
	int len = sizeof(arr) / sizeof(int);
	int i;
	
	quickSort(arr, 0, len - 1);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
