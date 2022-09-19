#include <iostream>
#include <vector>
#include <algorithm>

#define INF (987654321)

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

vi arr;
vvvi cache;

inline int sse(int i, int q) {
    return (arr[i] - q) * (arr[i] - q);
}

int min_sse(int i, int q, int s) {
    if (i == arr.size()) return 0;
    int& ret = cache[i][q][s];
    if (ret != -1) return ret;
    int sse_i = sse(i, q);
    ret = sse_i + min_sse(i + 1, q, s);
    if (s > 0) {
        for (int j = 1; q + j <= *arr.rbegin(); ++j) {
            ret = min(ret, sse_i + min_sse(i + 1, q + j, s - 1));
        }
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
        cache = vvvi(101, vvi(1001, vi(11, -1)));
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ret = INF;
        for (int q = *arr.begin(); q <= *arr.rbegin(); ++q) {
            ret = min(ret, min_sse(0, q, s - 1));
        }
        cout << ret << '\n';
    }
    return 0;
}