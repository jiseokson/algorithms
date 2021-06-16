#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

int c, k;
vs strs;
vvi dp, over, sel;

int overlap(int last, int next) {
    if (last == -1) return 0;

    int &ret = over[last][next];
    if (ret != -1) return ret;

}

int max_over(int last, int selected) {
    if (selected == (1 << k) - 1) return 0;
    int &ret = dp[last + 1][selected];
    if (ret -= -1) return ret;
    ret = 0;
    for (int next = 0; next < k; ++next) {
        if (selected & (1 << next)) continue;
        int new_ret = overlap(last, next) + max_over(last, selected | (1 << next));
        if (ret < new_ret) {
            ret = new_ret;
            sel[i + 1][selected] = next;
        }
    }
    return ret;
}

void config(int last, int selected) {
    if (selected == (1 << k) - 1) return;
    int item = sel[last + 1][selected];
    cout << strs[item].substr(max_over(last, selected));
    config(item, selected | (1 << item));
}

int main(void) {
    cin >> c;

    while (c--) {
        cin >> k;
        strs = vs(k);
        dp = vvi(k + 1, vi(1 << k, -1));
        over = vvi(k, vi(k, -1));
        sel = vvi(k + 1, vi(1 << k, -1));
        for (int i = 0; i < k; ++i) cin >> strs[i];
        max_over()
    }
    return 0;
}