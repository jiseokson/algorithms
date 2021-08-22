#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define SIG second

using namespace std;
using ui = unsigned int;
using uiui = pair<ui, ui>;

int n, k;

inline uiui first_sig() {
    return {1983, 1984};
}

inline uiui next_sig(uiui now) {
    uiui next = {(now.first * 214013ll + 2531011ll) % (1ll << 32), 0};
    next.second = next.first % 10000 + 1;
    return next;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> k >> n;

        uiui sig = first_sig();
        queue<uiui> q;
        ui ps = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            q.push(sig);
            ps += q.back().SIG;
            while (!q.empty() && ps > k) {
                ps -= q.front().SIG;
                q.pop();
            }
            if (ps == k) ++cnt;
            sig = next_sig(sig);
        }

        cout << cnt << '\n';
    }


    return 0;
}