#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int k;
vvi bino;

int morse(string str, int n, int m)
{
    if (n == 0 && m == 0) {
        --k;
        if (k == 0) {
            cout << str << "\n";
            return 1;
        }
        return 0;
    }
    if (bino[n + m][n] < k) {
        k -= bino[n + m][n];
        return 0;
    }
    if (n > 0 && morse(str + "-", n - 1, m)) return 1;
    if (m > 0 && morse(str + "o", n, m - 1)) return 1;
    return 0;

}

string kth(int n, int m, int k)
{
    if (n == 0) return string(m, 'o');
    if (m == 0) return string(n, '-');
    if (k <= bino[n + m - 1][n - 1])
        return "-" + kth(n - 1, m, k);
    return "o" + kth(n, m - 1, k - bino[n + m - 1][n - 1]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c, n, m;

    const int bino_max = 1000000000;
    bino = vvi(201, vi(201, 0));
    for (int i = 0; i <= 200; ++i) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; ++j)
            bino[i][j] = min(bino_max, bino[i - 1][j] + bino[i - 1][j - 1]);
    }
    cin >> c;
    while (c--) {
        cin >> n >> m >> k;
        cout << kth(n, m, k) << "\n";
        // morse("", n, m);
    }
    return 0;
}