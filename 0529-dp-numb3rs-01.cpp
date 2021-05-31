#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

typedef pair<int, int> ii;
typedef queue<ii> qii;

int n, d, p;
vvi g;
vvd dp;
qii q;

inline void get_input() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            if (a) g[i].push_back(j);
        }
}

inline void init() {
    dp[0][p] = 1.0;
    q.push({0, p});
}

void solve() {
    while (!q.empty()) {
        ii cur = q.front(); q.pop();
        int cur_day = cur.first, cur_node = cur.second;

        if (cur_day == d) return ;

        for (int &adj : g[cur_node]) {
            dp[cur_day + 1][adj] += dp[cur_day][cur_node] * (1.0 / g[cur_node].size());
            q.push({cur_day + 1, adj});
        }
    }
}

void print_ans() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        cout << dp[d][q] << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(10);

    int c;
    cin >> c;

    while (c--) {
        cin >> n >> d >> p;

        g = vvi(n);
        dp = vvd(d + 1, vd(n, 0.0));
        q = qii();

        get_input();
        init();
        solve();
        print_ans();
    }

    return 0;
}