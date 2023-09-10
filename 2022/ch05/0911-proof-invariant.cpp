#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int binary_search(const vi& arr, int x) {
    int lo = -1, hi = arr.size();
    // 1) lo < hi
    // 2) arr[lo] < x <= arr[hi]
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (x <= arr[mid])
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

void insertion_sort(vi& arr) {
    // 1) arr[0, i-1]이 정렬되어 있다.
    for (int i = 0; i < arr.size(); ++i)
        // 2) arr[j+1, i]의 모든 원소는 arr[j]보다 크다.
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            swap(arr[j - 1], arr[j]);
}

int main(void) {
    vi arr = {1, 1, 2, 3, 3, 3, 5, 5, 6, 8, 8};
    for (int i = 0; i < arr.size(); ++i)
        cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << ' ';
    cout << '\n';
    cout << binary_search(arr, 4) << '\n';

    vi arr2 = {4, 3, 6, 8, 3, 2, 1};
    insertion_sort(arr2);
    for (int i = 0; i < arr2.size(); ++i)
        cout << arr2[i] << ' ';

    return 0;
}