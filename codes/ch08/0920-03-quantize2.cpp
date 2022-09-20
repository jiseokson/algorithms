#include <iostream>
#include <vector>
#include <algorithm>

#define INF (987654321)

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi arr, psum_a, psum_a_2;
vvi cache;

void eval_psum() {
    psum_a[0] = arr[0];
    psum_a_2[0] = arr[0] * arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        psum_a[i] = psum_a[i - 1] + arr[i];
        psum_a_2[i] = psum_a_2[i - 1] + arr[i] * arr[i];
    }
}

int range_sum(const vi& psum, int lo, int hi) {
    if (lo == 0) return psum[hi];
    return psum[hi] - psum[lo - 1];
}

int range_min_sse(int lo, int hi) {
    int n = hi - lo + 1;
    int q = int((double)range_sum(psum_a, lo, hi) / n + 0.5);
    return range_sum(psum_a_2, lo, hi) - 2 * q * range_sum(psum_a, lo, hi) + n * q * q;
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
        psum_a = vi(n), psum_a_2 = vi(n);
        cache = vvi(101, vi(11, -1));
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr.begin(), arr.end());
        eval_psum();
        cout << min_sse(0, s - 1) << '\n';
    }
    return 0;
}