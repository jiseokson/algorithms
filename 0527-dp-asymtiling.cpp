#include <iostream>
using namespace std;

#define MOD 1000000007

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        int dp_all[101] = {1, 1};
        for (int i = 2; i <= n; ++i) dp_all[i] = (dp_all[i - 1] + dp_all[i - 2]) % MOD;

        int dp_sym[101] = {1, 1, 2, 1};
        for (int i = 4; i <= n; ++i) dp_sym[i] = (dp_sym[i - 2] + dp_sym[i - 4]) % MOD;

        cout << (dp_all[n] - dp_sym[n] + MOD) % MOD << '\n';
    }

    return 0;
}