#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int c, m;
vi E, Emod, Dmod;
vvvi dp;

int solve(int i, int mod, int selected) {
    if (i == Emod.size())
        return mod % m == 0? 1: 0;

    int &ret = dp[i][mod][selected];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int j = 0; j < Emod.size(); ++j) {
        if (selected & (1 << j)) continue;
        ret = (ret + solve(i + 1, (m + mod - (Emod[j] * Dmod[i]) % m) % m, selected + (1 << j))) % MOD;
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        string e;
        cin >> e >> m;

        E = vi(), Emod = vi();
        for (char d: e) {
            E.push_back(d - '0');
            Emod.push_back((d - '0') % m);
        }

        Dmod = vi(Emod.size(), 1);
        int step = 10 % m;
        for (auto i = Dmod.rbegin() + 1; i != Dmod.rend(); ++i)
            *i = *(i - 1) * step % m;

        dp = vvvi(Emod.size(), vvi(m, vi(1 << E.size(), -1)));
        int ans = 0;
        for (int i = 1; i < Emod.size(); ++i)
            if (E[0] > E[i])
                ans = (ans + solve(1, (2 * m - (Emod[i] * Dmod[0]) % m) % m, 1 << i)) % MOD;
                
        cout << ans << '\n';
    }

    return 0;
}