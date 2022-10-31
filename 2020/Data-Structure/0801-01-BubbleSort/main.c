#include <stdio.h>

// Bubble Sort
void sort(int arr[], const int len)
{
	int i, j;
	
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (! (arr[j] <= arr[j + 1])) {
				int temp       = arr[j + 1];
				    arr[j + 1] = arr[j];
				    arr[j]     = temp;
			}
		}
	}
}

int main(void)
{
	int arr[]  = {5, 4, 3, 2, 1, 5, 34, 10, 8, 7, 0, 2, -3, -45, 3};
	int i, len = sizeof(arr) / sizeof(int);
	
	sort(arr, len);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
		
	return 0;
}
