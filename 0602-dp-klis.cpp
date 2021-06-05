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
vi ret;

// a[i]로 시작하는 lis의 길이
ll lis(int i) {
    if (i == n) return 1;
    ll &ret = lis_dp[i];
    if (ret != -1) return ret;
    ret = 1;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j]) ret = max(ret, lis(j) + 1);
    return ret;
}


// a[i]가 선택된 경우에 생성 가능한 모든 lis의 개수
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

// 사전순 k번째 lis의 원소를 구성
void config(int i) {
    ret.push_back(a[i]);

    vii il;
    for (int j = i + 1; j <= n; ++j)
        if (a[i] < a[j] && lis(i) - 1 == lis(j))
            il.push_back({a[j], j});
    sort(il.begin(), il.end());

    for (ii iij : il) {
        int j = iij.second;
        if (klis(j) < k)
            k -= klis(j);
        else {
            config(j);
            break;
        }
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
        ret = vi();

        for (int i = 1; i <= n; ++i) cin >> a[i];

        cout << lis(0) - 1 << '\n';
        config(0);
        for (int i = 1; i < ret.size(); ++i) cout << ret[i] << ' ';
        cout << '\n';
    }

    return 0;
}