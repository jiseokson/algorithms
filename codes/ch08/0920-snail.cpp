#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vd = vector<double>;
using vvd = vector<vd>;

int c, n, m;
vvd cache;

double climb_prob(int climbed, int days) {
    if (days > m) return 0.0;
    if (climbed >= n) return 1.0;

    double& ret = cache[climbed][days];
    if (ret != -1) return ret;
    return ret = ((double)3 / 4) * climb_prob(climbed + 2, days + 1) + climb_prob(climbed + 1, days + 1) / 4;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(10);

    cin >> c;
    while (c--) {
        cin >> n >> m;
        cache = vvd(1001, vd(1001, -1));
        cout << climb_prob(0, 0) << '\n';
    }
    return 0;
}