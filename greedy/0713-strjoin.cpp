#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        vi L(n);
        FOR(i, n) cin >> L[i];

        int ans = 0;
        while (L.size() > 1) {
            sort(L.begin(), L.end(), greater<int>());
            int temp = 0;
            temp += L.back(); L.pop_back();
            temp += L.back(); L.pop_back();
            L.push_back(temp);
            ans += temp;
        }

        cout << ans << '\n';
    }

    return 0;
}