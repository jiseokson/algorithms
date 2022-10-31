#include <stdio.h>

// Insertion Sort
void sort(int arr[], int len)
{
	int i, j;
	int temp;
	
	for (i = 1; i < len; i++) {
		temp = arr[i];
		
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp)
				arr[j + 1] = arr[j];
			else
				break;
		}
		
		arr[j + 1] = temp;
	}
}

int main(void)
{
	int arr[]  = {5, 4, 3, 2, 1, 34, 32, 56, 34, -34, 4, 34};
	int i, len = sizeof(arr) / sizeof(int);
	
	sort(arr, len);
	
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
