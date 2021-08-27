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

inline int commonPrefix(const string &s, const vi &sa, int a, int b) {
    const int n = s.length();
    for (int i = 0; i < n - sa[a] && i < n - sa[b]; ++i)
        if (s[sa[a] + i] != s[sa[b] + i])
            return i;
    return min(n - sa[a], n - sa[b]);
}

int main(void) {
    string str;
    cin >> str;
    vi sa = getSuffixArray(str);
    const int n = str.length();
    int cnt = n - sa[0];
    for (int i = 1; i < n; ++i)
        cnt += n - sa[i] - commonPrefix(str, sa, i - 1, i);
    cout << cnt;
    return 0;
}