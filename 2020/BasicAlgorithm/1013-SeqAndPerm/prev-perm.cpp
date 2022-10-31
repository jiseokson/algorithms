#include <iostream>
using namespace std;

void swap(int& a, int &b)
{
    int t = a;
    a = b, b = t;
}

bool prevPermutation(int arr[], int len)
{
    int i, j;

    for (i = len - 1; 0 < i && arr[i - 1] < arr[i]; i--);
    if (i == 0) return false;

    for (j = len - 1; arr[i - 1] < arr[j]; j--);

    swap(arr[i - 1], arr[j]);
    for (int left = i, right = len - 1; left < right; left++, right--)
        swap(arr[left], arr[right]);

    return true;
}

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (prevPermutation(arr, n)) {
        for (int i : arr)
            cout << i << ' ';
    } else {
        cout << -1;
    }

    return 0;
}