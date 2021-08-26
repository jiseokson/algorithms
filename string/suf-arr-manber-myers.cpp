#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct Comparator {
    // grourp[i]: 첫 t글자를 기준으로 그룹화해 정렬, S[i]가 몇번째 그룹
    const vi &group;
    int t;
    Comparator(const vi &group_, int t_): group(group_), t(t_) {}
    bool operator()(int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vi getSuffixArray(const string &s) {
    int n = s.size();
    int t = 1;
    vi group(n + 1);
    for (int i = 0; i < n + 1; ++i) group[i] = s[i];
    group[n] = -1;
    vi perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    while (t < n) {
        Comparator compareUsing2t(group, t);
        sort(perm.begin(), perm.end(), compareUsing2t);
        for (int &i: perm) cout << s.substr(i) << '\n';
        cout << '\n';
        t *= 2;
        if (t >= n) break;
        vi newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < n; ++i)
            if (compareUsing2t(perm[i - 1], perm[i]))  // 다른 그룹이라면 (perm[i-1] < perm[i])
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else  // 같은 그룹이라면 (perm[i-1] == perm[i])
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        group = newGroup;
    }
    return perm;
}

int main(void) {
    string str;
    cin >> str;
    vi sa = getSuffixArray(str);
    for (int i: sa) cout << i << '\n';
    return 0;
}