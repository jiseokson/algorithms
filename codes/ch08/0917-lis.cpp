#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int n;
vi a, dp;

int lis(const vi& a) {
    if (a.size() == 0) return 0;
    int ret = 0;
    for (int i = 0; i < a.size(); ++i) {
        vi b;
        for (int j = i + 1; j < a.size(); ++j)
            if (a[i] < a[j]) b.push_back(a[j]);
        ret = max(ret, 1 + lis(b));
    }
    return ret;
}

int lis_dp(int i) {
    int& ret = dp[i];
    if (ret != -1) return ret;

    ret = 1;
    for (int j = i + 1; j < a.size(); ++j)
        if (a[i] < a[j]) ret = max(ret, 1 + lis_dp(j));
    return ret;
}

int main(void) {
    int max_lis = 0;
    for (int i = 0; i < a.size(); ++i)
        max_lis = max(max_lis, 1 + lis_dp(i));
    return 0;
}