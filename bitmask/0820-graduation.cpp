#include <iostream>
#include <cstring>

#define INF 100
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int n, k, l, m;
int pre[10], subject[10];
int dp[10][1 << 10];

void input() {
    memset(pre, 0, sizeof(pre));
    memset(subject, 0, sizeof(subject));
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> m >> l;
    REP(i, n) {
        int r;
        cin >> r;
        REP(j, r) {
            int p;
            cin >> p;
            pre[i] |= 1 << p;
        }
    }
    REP(i, m) {
        int c;
        cin >> c;
        REP(j, c) {
            int s;
            cin >> s;
            subject[i] |= 1 << s;
        }
    }
}

int search(int semester, int complete) {
    if (__builtin_popcount(complete) >= k) return 0;
    if (semester >= m) return INF;
    int &ret = dp[semester][complete];
    if (ret != -1) return ret;

    ret = min(INF, search(semester + 1, complete));

    int canTake = (subject[semester] & ~complete);
    for (int s = 0; s < n; ++s)
        if ((canTake & (1 << s)) && (pre[s] & complete) != pre[s])
            canTake &= ~(1 << s);
    for (int course = canTake; course; course = ((course - 1) & canTake))
        if (__builtin_popcount(course) <= l)
            ret = min(ret, search(semester + 1, complete | course) + 1);

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        input();
        int ans = search(0, 0);
        if (ans <= m) cout << ans;
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }

    return 0;
}