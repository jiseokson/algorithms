#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi getPi(const string &P) {
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

vi kmp(const string &S, const string &P) {
    vi pi = getPi(P);
    vi res;
    int j = 0;
    for (int i = 0; i < S.length(); ++i) {
        while (j > 0 && S[i] != P[j])
            j = pi[j - 1];
        if (S[i] == P[j]) {
            ++j;
            if (j == P.length()) {
                res.push_back(i - P.length() + 1);
                j = pi[j - 1];
            }
        }
    }
    return res;
}

int main(void) {
    string S, P;
    cin >> S >> P;
    for (int &begin: kmp(S, P))
        cout << begin << endl;
    return 0;
}