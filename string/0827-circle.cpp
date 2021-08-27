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
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vi getSuffixArray(string str) {
    const int n = str.length();
    vi group(n + 1);
    for (int i = 0; i < n; ++i) group[i] = str[i];
    group[n] = -1;
    vi perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;

    for (int t = 1; t < n; t *= 2) {
        Comparator compare2t(group, t);
        sort(perm.begin(), perm.end(), compare2t);
        vi newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < n; ++i)
            if (compare2t(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        group = newGroup;
    }
    return perm;
}

int main(void) {
    string str;
    cin >> str;
    vi sa = getSuffixArray(str + str);
    for (int i = 0; i < 2 * str.length(); ++i) {
        if (sa[i] >= str.length())
            continue;
        cout << (str + str).substr(sa[i], str.length());
        break;
    }
    return 0;
}