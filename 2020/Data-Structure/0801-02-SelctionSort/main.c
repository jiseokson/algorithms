#include <stdio.h>

//Selection Sort
void sort(int arr[], const int len)
{
	int i, j, minIndex;
	int temp;
	
	for (i = 0; i < len - 1; i++) {
		minIndex = i;
		
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
				
		temp          = arr[i];
		arr[i]        = arr[minIndex];
		arr[minIndex] = temp;
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
