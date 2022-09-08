#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i, a, b) for (int (i) = a; (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define MAX (100);

using namespace std;
using msi = map<string, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int n, m;
msi wm;
vvi can_eat; // 음식i를 먹을수 있는 사람 정보
vi edible;
int ans;

void solve(int i, int cnt) {
    if (cnt >= ans)
        return;
    if (find(edible.begin(), edible.end(), 0) == edible.end()) {
        ans = min(ans, cnt);
        return;
    }
    if (i == m)
        return;

    solve(i + 1, cnt);
    for (int p: can_eat[i])
        ++edible[p];
    solve(i + 1, cnt + 1);
    for (int p: can_eat[i])
        --edible[p];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        wm = msi();
        can_eat = vvi(m, vi());
        edible = vi(n, 0);
        ans = MAX;

        REP(i, n) {
            string name;
            cin >> name;
            wm[name] = i;
        }
        REP(i, m) {
            int ce;
            cin >> ce;
            REP(j, ce) {
                string name;
                cin >> name;
                can_eat[i].push_back(wm[name]);
            }
        }

        solve(0, 0);
        cout << ans << '\n';
    }

    return 0;
}