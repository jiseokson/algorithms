#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

inline int fact(int n) {
    static vi fact_dp(20, -1);
    if (n == 0) return 1;
    int &ret = fact_dp[n];
    if (ret != -1) return ret;
    return ret = n * fact(n - 1);
}

inline int perm_idx(const vi a) {
    int ret = 0;
    for (int i = 0; i < a.size(); ++i) {
        int less = 0;
        for (int j = i + 1; j < a.size(); ++j)
            if (a[j] < a[i]) ++less;
        ret += fact(a.size() - i - 1) * less;
    }
    return ret;
}

int main(void) {
    vi a = {1, 2, 3, 4, 5};
    do {
        for_each(a.begin(), a.end(), [] (int n) { cout << n << ' '; });
        cout << ": at " << perm_idx(a) << '\n';
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}