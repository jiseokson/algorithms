#include <iostream>
#include <vector>
#include <string>

using namespace std;
using vi = vector<int>;

vi getPi(const string &p) {
    vi pi = vi(p.length(), 0);
    int j = 0;
    for (int i = 1; i < p.length(); ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int getMaxOverlap(const string &str, const string &rev) {
    vi pi = getPi(rev);
    int j = 0;
    for (int i = 0; i < str.length(); ++i) {
        while (j > 0 && str[i] != rev[j])
            j = pi[j - 1];
        if (str[i] == rev[j]) {
            ++j;
            if (j == rev.length())
                return rev.length();
        }
    }
    return j;
}

int main(void) {
    string str;
    cin >> str;
    string rev = string(str.rbegin(), str.rend());
    int overlap = getMaxOverlap(str, rev);
    cout << string(str.begin(), str.end() - overlap) << rev << endl;
    return 0;
}