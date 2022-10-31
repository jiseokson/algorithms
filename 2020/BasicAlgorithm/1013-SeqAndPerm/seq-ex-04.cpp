#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans = 0;
    do {
        int temp = 0;
        for (int i = 1; i < n; i++)
            temp += abs(arr[i - 1] - arr[i]);
        if (ans < temp)
            ans = temp;
    } while (next_permutation(arr, arr + n));

    cout << ans;

    return 0;
}