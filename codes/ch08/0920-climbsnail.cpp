#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c, m, n;
vvi cache;

int count(int days, int climbed) {
    if (days == m) return climbed > n;
    int& ret = cache[days][climbed];
    if (ret != -1) return ret;
    return ret = count(days + 1, climbed + 1) + count(days + 1, climbed + 2);
}

int pow(int a, int b) {
    int ret = 1;
    for (int i = 0; i < b; ++i) {
        ret *= a;
    }
    return ret;
}

int main(void) {
    cin >> c;
    while (c--) {
        cin >> m >> n;
        cache = vvi(m + 1, vi(n + 1, -1));
        cout << count(0, 0) / pow(2, m) << '\n';
    }
    return 0;
}