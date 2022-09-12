#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c;
vi clocks(16, 0);
vi press(10, 0);
vvi switches = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

void adjust_press(int sign) {
    for (int i = 0; i < press.size(); ++i)
        for (int clock: switches[i])
            clocks[clock] += sign * press[i];
}

bool is_aligned() {
    adjust_press(1);
    bool ok = true;
    for (int i = 0; i < clocks.size(); ++i) {
        if (clocks[i] % 4 != 0) {
            ok = false;
            break;
        }
    }
    adjust_press(-1);
    return ok;
}

int press_sum() {
    int ret = 0;
    for (int i = 0; i < press.size(); ++i)
        ret += press[i];
    return ret;
}

int min_press(int i) {
    if (i == press.size())
        return is_aligned()? press_sum(): INF;
    int ret = INF;
    for (int p = 0; p <= 3; ++p) {
        press[i] = p;
        ret = min(ret, min_press(i + 1));
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        for (int i = 0; i < 16; ++i) {
            cin >> clocks[i];
            clocks[i] = (clocks[i] / 3) % 4;
        }
        int ans = min_press(0);
        cout << (ans == INF? -1: ans) << '\n';
    }

    return 0;
}