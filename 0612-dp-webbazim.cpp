#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int c, m;
vi E, Emod, Dmod;
vvi dp;

int solve(int mod, int selected) {
    if (selected == (1 << Emod.size()) - 1)
        return mod == 0? 1: 0;
    int &ret = dp[mod][selected];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < Emod.size(); ++i) {
        if (selected & (1 << i)) continue;
        ret = (ret + solve((2 * mod - (Emod[i] * Emod[i]) % m) % m, selected + (1 << i))) % MOD;
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

        int ans = 0;
        dp = vvi(m, vi(1 << Emod.size(), -1));
        for (int i = 1; i < Emod.size(); ++i)
            if (E[0] > E[i])
                ans = (ans + solve((2 * m - (Dmod[i] * Emod[i]) % m) % m, 1 << i)) % MOD;
                
        cout << ans << '\n';
    }

    return 0;
}