#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n;

vvi mul(vvi &a, vvi &b) {
    vvi ret(n, vi(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}

vvi pow(vvi &a, ll b) {
    if (b == 1) return a;
    vvi p = pow(a, b / 2);
    vvi ret = mul(p, p);
    return b % 2 == 0 ? ret : mul(ret, a);
}

int main(void) {
    ll b;
    cin >> n >> b;
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    vvi ret = pow(a, b);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ret[i][j] % 1000 << ' ';
        cout << '\n';
    }
    return 0;
}