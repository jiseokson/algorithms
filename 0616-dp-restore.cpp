#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

int c, k;
vs strs;
vvi dp, ans, over_memo;

void get_input() { // ok
    cin >> k;
    strs = vs();
    for (int i = 0; i < k; ++i) {
        string temp;
        cin >> temp;
        bool ok = true;
        for (string s: strs) {
            for (int j = 0; j < s.length(); ++j) {
                if (s.substr(j, temp.length()) == temp) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) strs.push_back(temp);
    }
    k = strs.size();
}

void init() {
    dp = vvi(k + 1, vi(1 << k, -1));
    ans = vvi(k + 1, vi(1 << k, -1));
    over_memo = vvi(k, vi(k, -1));
}

int over(int last, int next) { // ok
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
    ret = 0;
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