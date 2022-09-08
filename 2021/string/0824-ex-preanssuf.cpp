#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

vi getPi(const string &p) {
    vi pi(p.length(), 0);
    int j = 0;
    for (int i = 1; i < p.length(); ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main(void) {
    string str;
    cin >> str;
    vi pi = getPi(str);
    int n = str.length();
    while (n > 0) {
        cout << n << ' ' ;
        n = pi[n - 1];
    }
    return 0;
}