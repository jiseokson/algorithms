#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;

int majority1(const vi& arr) {
    int majority = -1, majority_count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int count = 0;
        for (int j = 0; j < arr.size(); ++j)
            if (arr[i] == arr[j])
                ++count;
        if (count > majority_count) {
            majority = arr[i];
            majority_count = count;
        }
    }
    return majority;
}

int majority2(const vi& arr) {
    vi counts(101, 0);
    for (int i = 0; i < arr.size(); ++i)
        ++counts[arr[i]];

    int majority = 0;
    for (int i = 0; i < counts.size(); ++i)
        if (counts[i] > counts[majority])
            majority = counts[i];

    return majority;
}

vd moving_average1(const vd& arr, int m) {
    vd ret;
    for (int i = m - 1; i < arr.size(); ++i) {
        double sum = 0.0;
        for (int j = 0; j < m; ++j)
            sum += arr[i - j];
        ret.push_back(sum / m);
    }
    return ret;
}

vd moving_average2(const vd& arr, int m) {
    vd ret;
    double partial_sum = 0;
    for (int i = 0; i < m - 1; ++i)
        partial_sum += arr[i];
    for (int i = m - 1; i < arr.size(); ++i) {
        partial_sum += arr[i];
        ret.push_back(partial_sum / m);
        partial_sum -= arr[i - m + 1];
    }
    return ret;
}

vi factor(int n) {
    if (n == 1) return vi(1, 1);
    vi ret;
    for (int d = 2; n > 1; ++d) {
        while (n % d == 0) {
            n /=d;
            ret.push_back(d);
        }
    }
    return ret;
}

void selection_sort(vi& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        // int min_idx = i;
        // for (int j = i + 1; j < arr.size(); ++j)
        //     if (arr[j] < arr[min_idx])
        //         min_idx = j;
        // swap(arr[i], arr[min_idx]);
        swap(arr[i], *min_element(arr.begin() + i, arr.end()));
    }
}

void insertion_sort(vi& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            --j;
        }
    }
}

int binary_search(vi& arr, int x) {
    int lo = -1, hi = arr.size();
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (x <= arr[mid])
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main(void) {
    cout << "Majority functions\n";
    vi arr = {1, 1, 2, 2, 2, 2, 3, 4, 4, 5};
    cout << majority1(arr) << '\n';
    cout << majority2(arr) << '\n';

    for (int d: factor(126))
        cout << d << ' ';
    cout << '\n';

    vi arr2 = {4, 2, 6, 7, 5, 9, 1, 3};
    selection_sort(arr2);
    for (int i = 0; i < arr2.size(); ++i)
        cout << arr2[i] << ' ';
    cout << '\n';

    vi arr3 = {4, 2, 6, 7, 5, 9, 1, 3};
    insertion_sort(arr3);
    for (int i = 0; i < arr3.size(); ++i)
        cout << arr3[i] << ' ';
    cout << '\n';

    vi arr4 = {1, 2, 3, 3, 4, 4, 4, 4};
    int i = binary_search(arr4, 4);
    cout << i << ' ' << arr4[i] << '\n';

    vi arr5 = {1, 2, 2, 4, 5, 6};
    int j = binary_search(arr5, 3);
    cout << j << ' ' << arr5[j] << '\n';

    return 0;
}