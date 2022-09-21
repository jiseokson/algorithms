#include <iostream>
#include <vector>
#include <algorithm>

#define MOD (1000000007)

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c, n;
vi tiling_cache, sym_tiling_cache;

int tiling(int i) {
    if (i <= 0) return i == 0;
    int& ret = tiling_cache[i];
    if (ret != -1) return ret;
    return ret = (tiling(i - 1) + tiling(i - 2)) % MOD;
}

int sym_tiling(int i) {
    int& ret = sym_tiling_cache[i];
    if (ret != -1) return ret;
    if (i % 2 == 0) ret = (tiling(n / 2) + tiling(n / 2 - 1)) % MOD;
    else ret = tiling((n - 1) / 2);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    tiling_cache = vi(101, -1);
    sym_tiling_cache = vi(101, -1);

    cin >> c;
    while (c--) {
        cin >> n;
        cout << (tiling(n) - sym_tiling(n) + MOD) % MOD << '\n';
    }

    return 0;
}