#include <iostream>
#include <vector>

#define MAX_N 1000000000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, k;
vvi dp;

int morse_cnt(int n, int m) {
    if (n < 0 || m < 0) return -1;
    if (n == 0 || m == 0) return 1;
    int &ret = dp[n][m];
    if (ret != -1) return ret;
    ret = min(morse_cnt(n - 1, m) + morse_cnt(n, m - 1), MAX_N);
    return ret;
}

void config(int n, int m) {
    if (n == 0 && m == 0) {
        cout << '\n';
        return ;
    }

    int lcnt = morse_cnt(n - 1, m);
    if (k <= lcnt) {
        cout << '-';
        config(n - 1, m);
    } else {
        cout << 'o';
        k = k - lcnt;
        config(n, m - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        cin >> n >> m >> k;
        dp = vvi(n + 1, vi(m + 1, -1));
        config(n, m);
    }

    return 0;
}