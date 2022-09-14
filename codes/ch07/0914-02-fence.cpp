#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int c, n;
vi a;

int max_area(int lo, int hi) {
    if (lo == hi) return a[lo];
    if (lo > hi) return 0;

    int mid = (lo + hi) / 2;
    int left = mid, right = mid + 1;
    int height = min(a[left], a[right]);
    int middle = 0;
    while (lo <= left && right <= hi) {
        int width = right - left + 1;
        height = min(height, min(a[left], a[right]));
        middle = max(middle, width * height);
        if ((left == lo) || (right < hi && a[left - 1] < a[right + 1]))
            ++right;
        else
            --left;
    }

    return max(middle, max(max_area(lo, mid), max_area(mid + 1, hi)));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> n;
        a = vi(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << max_area(0, n - 1) << '\n';
    } 

    return 0;
}