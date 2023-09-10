#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 10000000;

vvi cache;

int poly(int a, int b)
{
    if (b == 0) return 1;
    int &ret = cache[a][b];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; 0 <= b - i; ++i)
        ret = (ret + (a + i - 1) * poly(i, b - i)) % mod;
    return ret % mod;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        cache = vvi(n + 1, vi(n + 1, -1));
        int ans = 0;
        for (int i = 1; 0 <= n - i; ++i)
            ans = (ans + poly(i, n - i)) % mod;
        cout << ans % mod << "\n";
    }

    return 0;
}