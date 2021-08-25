#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi getPi(string P) {
    vi pi(P.length(), 0);
    int j = 0;
    for (int i = 1; i < P.length(); ++i) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
    return pi;
}

int kmpFirst(string S, string P) {
    vi pi = getPi(P);
    int j = 0;
    for (int i = 0; i < S.length(); ++i) {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j]) {
            ++j;
            if (j == P.length())
                return i - P.length() + 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        string state[101];
        for (int i = 0; i < n + 1; ++i)
            cin >> state[i];
        int len = state[0].length();
        int ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            int first = kmpFirst(state[i] + state[i], state[i - 1]);
            ans += (i % 2? first: (len - first) % len);
        }
        cout << ans << '\n';
    }

    return 0;
}