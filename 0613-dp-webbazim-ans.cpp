#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int c, m;
string e;

vi E, Emod, Dmod;
vvvi dp;

int solve(int i, int mod, bool less, int check) {
    if (i == E.size())
        return mod % m == 0? 1: 0;

    int &ret = dp[mod][less][check];
    if (ret != -1) return ret;

    ret = 0;
    for (int j = 0; j < E.size(); ++j) {
        if (less) {
            if (check && (1 << j)) continue;
            ret = (ret + solve(i + 1, (m + mod - (Emod[j] * Dmod[i]) % m) % m, less, check + (1 << j))) % MOD;
        } else {
            if ()
            //
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        cin >> e >> m;

        E = vi(), Emod = vi();
        for (char d: e)
            E.push_back(d - '0');
        sort(E.begin(), E.end());
        for (int d: E)
            Emod.push_back(d % m);

        Dmod = vi(E.size(), 1);
        int step = 10 % m;
        for (auto i = Dmod.rbegin() + 1; i != Dmod.rend(); ++i)
            *i = *(i - 1) * step % m;

        dp = vvvi(2, vvi(m, vi(1 << E.size(), -1)));
        cout << solve(0, 0, false, 0); << '\n';
    }

    return 0;
}