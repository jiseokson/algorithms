#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INT_MAX (((ll)1 << 31) - 1)

// a[0] == -inf
// a[1 ~ n]: 입력받은 수열
int c, n, k;
vi a;
vll lis_dp, klis_dp;

ll lis(int i) {
    if (i == n) return 1;
    ll &ret = lis_dp[i];
    if (ret != -1) return ret;
    ret = 1;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j]) ret = max(ret, lis(j) + 1);
    return ret;
}

ll klis(int i) {
    if (lis(i) == 1) return 1;
    ll &ret = klis_dp[i];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j] && lis(i) - 1 == lis(j))
            ret += klis(j);
    return min(ret, INT_MAX);
}

void config(int i) {
    if (lis(i) == 1) {
        cout << '\n';
        return;
    }

    vii il;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j] && lis(i) - 1 == lis(j))
            il.push_back({a[j], j});
    sort(il.begin(), il.end());

    for (ii iij : il) {
        int j = iij.second;
        if (k <= klis(j)) {
            cout << a[j] << ' ';
            config(j);
            break;
        }
        k -= klis(j);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> c;

    while (c--) {
        cin >> n >> k;

        a = vi(n + 1, 0);
        lis_dp = vll(n + 1, -1);
        klis_dp = vll(n + 1, -1);

        for (int i = 1; i <= n; ++i) cin >> a[i];

        cout << lis(0) - 1 << '\n';
        config(0);
    }

    return 0;
}