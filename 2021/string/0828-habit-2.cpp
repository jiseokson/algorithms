#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct Comparator {
    const vi &group;
    int t;
    Comparator(const vi &group, int t): group(group), t(t) {}
    bool operator()(int a, int b) {
        return group[a] != group[b]? group[a] < group[b]: group[a + t] < group[b + t];
    }
};

vi getSuffixArray(string s) {
    const int n = s.length();
    vi group(n + 1);
    for (int i = 0; i < n; ++i) group[i] = s[i];
    group[n] = -1;
    vi perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;

    for (int t = 1; t < n; t *= 2) {
        Comparator compare2t(group, t);
        sort(perm.begin(), perm.end(), compare2t);

        vi newGroup(n + 1);
        newGroup[perm[0]] = 0;
        newGroup[n] = -1;
        for (int i = 1; i < n; ++i)
            if (compare2t(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        group = newGroup;
    }
    return perm;
}

int commonPrefix(string &s, int i, int j) {
    const int n = s.length();
    int cp = 0;
    while (i < n && j < n && s[i] == s[j])
        ++i, ++j, ++cp;
    return cp;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int k;
        string s;
        cin >> k >> s;
        vi a = getSuffixArray(s);
        int lf = 0;
        for (int i = 0; i + k <= s.length(); ++i)
            lf = max(lf, commonPrefix(s, a[i], a[i + k - 1]));
        cout << lf << '\n';
    }
    return 0;
}