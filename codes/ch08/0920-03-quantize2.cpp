#include <iostream>
#include <vector>
#include <algorithm>

#define INF (987654321)

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi arr, psum;
vvi cache;

// void eval_psum() {
//     psum[0] = arr[0];
//     for (int i = 1; i < arr.size(); ++i) {
//         psum[i] = psum[i - 1] + arr[i];
//     }
// }

// int range_mean(int lo, int hi) {
//     int n = hi - lo + 1;
//     if (lo == 0) return int((double)psum[hi] / n + 0.5);
//     return int((double)(psum[hi] - psum[lo - 1]) / n + 0.5);
// }

int eval_sse(int lo, int hi, int q) {
    int ret = 0;
    for (int i = lo; i <= hi; ++i)
        ret += (arr[i] - q) * (arr[i] - q);
    return ret;
}

int range_min_sse(int lo, int hi) {
    int ret = INF;
    for (int q = arr[lo]; q <= arr[hi]; ++q) {
        ret = min(ret, eval_sse(lo, hi, q));
    }
    return ret;
    // int q = range_mean(lo, hi);
    // return eval_sse(lo, hi, q);
}

int min_sse(int i, int s) {
    if (i == arr.size()) return 0;
    if (s == 0) return range_min_sse(i, arr.size() - 1);

    int& ret = cache[i][s];
    if (ret != -1) return ret;

    ret = INF;
    for (int j = 1; i + j <= arr.size(); ++j) {
        ret = min(
            ret,
            range_min_sse(i, i + j - 1) + min_sse(i + j, s - 1)
        );
    }
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c, n, s;
    cin >> c;
    while (c--) {
        cin >> n >> s;
        arr = vi(n);
        psum = vi(n);
        cache = vvi(101, vi(11, -1));
        for (int i = 0; i < n; ++i) cin >> arr[i];
        // eval_psum();
        sort(arr.begin(), arr.end());
        cout << min_sse(0, s - 1) << '\n';
    }
    return 0;
}