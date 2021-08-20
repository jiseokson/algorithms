#include <iostream>
#include <cstring>

#define MAX_ANS 100
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

int n, k, m, l;
int subject[10];
int pre[10];
int ans = MAX_ANS;

void input() {
    ans = MAX_ANS;
    memset(subject, 0, sizeof(subject));
    memset(pre, 0, sizeof(pre));
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

inline bool isPreComplete(int subset, int complete) {
    for (int i = 0; i < n; ++i) {
        if (!(subset & (1 << i))) continue;
        if (pre[i] & ~complete) return false;
    }
    return true;
}

void search(int semester, int complete) {
    if (semester >= ans)
        return;
    if (__builtin_popcount(complete) >= k) {
        ans = min(ans, semester - 1);
        return;
    }
    if (semester == m)
        return;

    for (int subset = subject[semester]; subset; subset = ((subset - 1) & subject[semester])) {
        if (__builtin_popcount(subset) <= l && !(subset & complete) && isPreComplete(subset, complete)) {
            complete |= subset;
            search(semester + 1, complete);
            complete &= ~subset;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        input();
        search(0, 0);
        if (ans <= m) cout << ans;
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }

    return 0;
}