#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

int c, k;
vs strs;
vvi dp, ans, over_memo;

// True if a is sub string of b
inline bool sub(string &a, string &b) {
    for (int i = 0; i < b.length(); ++i)
        if (b.substr(i, a.length()) == a)
            return true;
    return false;
}

void get_input() {
    cin >> k;
    strs = vs();
    vs temp(k);
    for (int i = 0; i < k; ++i) cin >> temp[i];

    vi super(k);
    for (int i = 0; i < k; ++i) super[i] = i;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < k; ++j)
            if (i != j && sub(temp[i], temp[j])) super[i] = j;

    for (int i = 0; i < k; ++i)
        if (super[i] == i) strs.push_back(temp[i]);
    k = strs.size();
}

void init() {
    dp = vvi(k + 1, vi(1 << k, -1));
    ans = vvi(k + 1, vi(1 << k, -1));
    over_memo = vvi(k, vi(k, -1));
}

int over(int last, int next) {
    if (last == -1) return 0;
    int &ret = over_memo[last][next];
    if (ret != -1) return ret;
    string &last_str = strs[last], &next_str = strs[next];
    int pre = last_str.length() > next_str.length()? last_str.length() - next_str.length() + 1: 1;
    for (; pre <= last_str.length(); ++pre) {
        ret = last_str.length() - pre;
        if (last_str.substr(pre) == next_str.substr(0, ret))
            break;
    }
    return ret;
}

int max_over(int last, int selected) {
    if (selected == (1 << k) - 1) return 0;
    int &ret = dp[last + 1][selected];
    if (ret != -1) return ret;

    ret = -1;
    for (int next = 0; next < k; ++next) {
        if (selected & (1 << next)) continue;
        int new_ret = over(last, next) + max_over(next, selected | (1 << next));
        if (ret < new_ret) {
            ret = new_ret;
            ans[last + 1][selected] = next;
        }
    }
    return ret;
}

void config(int last, int selected) {
    if (selected == (1 << k) - 1) {
        cout << '\n';
        return;
    }
    int next = ans[last + 1][selected];
    cout << strs[next].substr(over(last, next));
    config(next, selected | (1 << next));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        get_input();
        init();
        max_over(-1, 0);
        config(-1, 0);
    }

    return 0;
}