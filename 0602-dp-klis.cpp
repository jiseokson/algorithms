#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;
vi a;
vi lis_dp, klis_dp;

int lis(int i) {
    if (i == n) return 1;
    int &ret = lis_dp[i];
    if (ret != -1) return ret;
    ret = 1;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j]) ret = max(ret, lis(j) + 1);
    return ret;
}

// int klis(int i) {
//     if (lis(i) == 1) return 1;
//     int &ret = klis_dp[i];
//     if (ret != -1) return ret;
//     ret = 0;
//     for (int j = i + 1; j <= n; ++j)
//         if (a[i] < a[j] && lis(i) - 1 == lis(j))
//             ret += klis(j);
//     return ret;
// }

void config(vi &ret, int i) {
    if (k < 1) return ;
    if (lis(i) == 1) {
        if (k == 1) {
            for (int i = 0; i < ret.size(); ++i) cout << ret[i] << ' ';
            cout << '\n';
        }
        --k;
        return ;
    }

    // if (lis(i) == 1) {
    //     for (int i = 0; i < ret.size(); ++i) cout << ret[i] << ' ';
    //     cout << '\n';
    //     return ;
    // }

    vi q;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j] && lis(i) - 1 == lis(j))
            q.push_back(j);
    sort(q.begin(), q.end(),
        [&a] (int i, int j) -> bool {
            return a[i] < a[j];
        }
    );

    // int s = 0;
    for (int i = 0; i < q.size(); ++i) {
        // s += klis(q[i]);
        // if (k <= s) {
            ret.push_back(a[q[i]]);
            config(ret, q[i]);
            ret.pop_back();
        // }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        cin >> n >> k;
        a = vi(n + 1, 0);
        lis_dp = vi(n + 1, -1);
        klis_dp = vi(n + 1, -1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vi ret;
        cout << lis(0) - 1 << '\n';
        config(ret, 0);
    }

    return 0;
}