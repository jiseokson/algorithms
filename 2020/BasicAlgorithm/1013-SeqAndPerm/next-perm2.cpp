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

    // if (next_permutation(arr, arr + n)) {
    //     for (int& i : arr)
    //         cout << i << ' ';
    // } else {
    //     cout << -1;
    // }

    do {
        for (int i : arr)
            cout << i << ' ';
        cout << '\n';
    } while (next_permutation(arr, arr + n));

    return 0;
}