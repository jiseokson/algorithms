#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define NEGINF -100000

int n, w;
vi vol, need;
vvi dp;
// vvi selects;

int solve(int i, int vol_sum) {
    if (vol_sum > w) return NEGINF;
    if (i == n) return 0;

    int &ret = dp[i][vol_sum];
    if (ret != -1) return ret;

    int ret1 = need[i] + solve(i + 1, vol_sum + vol[i]);
    int ret2 = solve(i + 1, vol_sum);

    // if (ret1 > ret2) {
    //     selects[i][vol_sum] = true;
    //     ret = ret1;
    // } else {
    //     selects[i][vol_sum] = false;
    //     ret = ret2;
    // }

    return ret = ret1 > ret2 ? ret1 : ret2;
}

void config_selects(vi &selected_items, int i, int vol_sum) {
    if (i == n) return;
    if (solve(i, vol_sum) != solve(i + 1, vol_sum)) {
        selected_items.push_back(i);
        config_selects(selected_items, i + 1, vol_sum + vol[i]);
    } else {
        config_selects(selected_items, i + 1, vol_sum);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int c;
    cin >> c;

    while (c--) {
        cin >> n >> w;
        
        map<int, string> m;
        vol = vi(n), need = vi(n);
        dp = vvi(101, vi(1001, -1));
        // selects = vvi (101, vi(1001, -1));
        vi selected_items;

        for (int i = 0; i < n; ++i) {
            string name;
            cin >> name >> vol[i] >> need[i];
            m.insert({i, name});
        }

        int max_need = solve(0, 0);
        config_selects(selected_items, 0, 0);
        
        cout << max_need << ' ' << selected_items.size() << '\n';
        for (int &item : selected_items) cout << m[item] << '\n';
    }

    return 0;
}