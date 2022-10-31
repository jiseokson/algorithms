#include <stdio.h>

int binarySearch(int target, int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	
	if (left > right)
		return -1;
		
	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return binarySearch(target, arr, left, mid - 1);
	else
		return binarySearch(target, arr, mid + 1, right);
}

int ISearch(int target, int arr[], int left, int right)
{
	if (! ((arr[left] < target) && (target < arr[right])))
		return -1;
		
	int mid = (double)(target - arr[left]) / (arr[right] - arr[left]) * (right - left) + left;
	
	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return ISearch(target, arr, left, mid - 1);
	else
		return ISearch(target, arr, mid + 1, right);
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	
	printf("%d\n", ISearch(5, arr, 0, 4));
	
	return 0;
}
