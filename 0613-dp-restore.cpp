#include <iostream>
#include <vector>

#define LEN_MAX (15 * 40)

using namespace std;

typedef vector<string> vs;
typedef vector<vector<vector<int>>> vvvi;

int c, k;
vs strs;
vvvi dp;

int min_len(string data, int last_idx, int last_len, int selected) {
    if (selected == (1 << k) - 1) return last_len;
    int &ret = dp[last_idx + 1][last_len][selected];
    if (ret != -1) return ret;
    ret = LEN_MAX;
    for (int i = 0; i < k; ++i) {
        if (selected & (1 << i)) continue;
        // Todo: compute overlap
        if (overlap < strs[i].length()) {
            string next_data = data + strs[i].substr(overlap);
            ret = min(ret, min_len(next_data, i, next_data.length(), selected + (1 << i)));
        } else
            ret = min(ret, min_len(data, i, last_len, selected + (1 << i)));
    }
    return ret;
}

int main(void) {
    cin >> c;

    while (c--) {
        cin >> k;
        strs = vs(k);
        dp = vvvi(k + 1, vvi(LEN_MAX + 1, vi(1 << k, -1)));
        for (int i = 0; i < k; ++i) cin >> strs[i];
        cout << min_len("", -1, 0, 0) << '\n';
    }

    return 0;
}