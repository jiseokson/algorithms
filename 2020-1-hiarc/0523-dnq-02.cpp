#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int solve(vi &a, int l, int r){
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    int lo = mid, hi = mid + 1;
    int ret = max(solve(a, l, mid), solve(a, mid + 1, r));
    int h = min(a[lo], a[hi]);
    ret = max(ret, h * (hi - lo + 1));
    while (l < lo || hi < r) {
        if (l <= lo - 1 && (hi == r || a[lo - 1] > a[hi + 1])) {
            --lo;
            h = min(h, a[lo]);
        }
        else {
            ++hi;
            h = min(h, a[hi]);
        }
        ret = max(ret, h * (hi - lo + 1));
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(a, 0, n - 1);
    return 0;
}