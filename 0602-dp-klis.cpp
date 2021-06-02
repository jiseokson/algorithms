#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n, k;
vi a;
vi lis_dp, lis_cnt_dp;

int max_lis_len = 1;

int lis(int i) {
    if (i == n - 1) return 1;
    int &ret = lis_dp[i];
    if (ret != -1) return ret;
    ret = 1;
    for (int j = i + 1; j < n; ++j)
        if (a[i] < a[j]) ret = max(ret, lis(j) + 1);
    max_lis_len = max(max_lis_len, ret);
    return ret;
}

int lis_cnt(int i) {
    if (i == n - 1) return 1;
    int &ret = lis_cnt_dp[i];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = i + 1; j < n; ++j)
        if (lis(i) - 1 == lis(j)) ret += lis_cnt(j);
    return ret = max(ret, 1);
}

void config(int i) {
    //
}

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        cin >> n >> k;
        a = vi(n);
        lis_dp = vi(n, -1), lis_cnt_dp = vi(n, -1);
        max_lis_len = 1;
        for (int i = 0; i < n; ++i) cin >> a[i];
    }

    return 0;
}