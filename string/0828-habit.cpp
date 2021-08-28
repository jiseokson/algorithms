#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct Comparator {
    const vi &group;
    const int t;
    Comparator(const vi &g, const int t): group(g), t(t) {}
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

int main(void) {
    int tc;
    cin >> tc;

    while (tc--) {
        int k;
        string s;
        cin >> k;
        cin >> s;
        vi a = getSuffixArray(s);
        const int n = s.length();
        int ans = 1;
        for (int cp = 1; cp < n; ++cp) {
            int cnt = 1;
            int maxCnt = 1;
            for (int i = 1; i < n; ++i) {
                if (n - a[i - 1] < cp)
                    cnt = 1;
                else if (n - a[i] >= cp && s.substr(a[i - 1], cp) == s.substr(a[i], cp))
                    ++cnt;
                maxCnt = max(maxCnt, cnt);
            }
            ans = max(ans, maxCnt);
            if (maxCnt < k) break;
        }
        cout << ans << '\n';
    }
    return 0;
}