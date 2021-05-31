#include <iostream>
#include <vector>
using namespace std;

#define INF 50000

int eval(string &n, int i, int f) {
    bool ok = true;
    for (int j = i; j < f; ++j) {
        if (n[i] != n[j]) {
            ok = false;
            break;
        }
    }
    if (ok) return 1;

    ok = true;
    int d = n[i + 1] - n[i];
    for (int j = i + 1; j < f; ++j) {
        if (n[j] - n[j - 1] != d) {
            ok = false;
            break;
        }
    }
    if (ok && d * d == 1) return 2;
    if (ok) return 5;

    ok = true;
    for (int j = i; j < f; ++j) {
        if (n[i + (j - i) % 2] != n[j]) {
            ok = false;
            break;
        }
    }
    if (ok) return 4;

    return 10;
}

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        string n;
        cin >> n;
        vector<int> dp(n.length() + 1, INF);
        for (int i = 3; i <= 5; ++i) dp[i] = eval(n, 0, i);
        for (int i = 6; i <= n.length(); ++i) {
            for (int j = 3; j <= 5; ++j)
                dp[i] = min(dp[i], dp[i - j] + eval(n, i - j, i));
        }
        cout << dp[n.length()] << '\n';
    }

    return 0;
}