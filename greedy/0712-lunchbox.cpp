#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t ;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi M(n), E(n);
        FOR(i, n) cin >> M[i];
        FOR(i, n) cin >> E[i];

        vii arr;
        FOR(i, n) arr.push_back({-E[i], M[i]});
        sort(arr.begin(), arr.end());

        int ans = 0;
        int sm = 0;
        FOR(i, n) {
            ans = max(ans, sm - arr[i].first + arr[i].second);
            sm += arr[i].second;
        }
        cout << ans << '\n';
    }

    return 0;
}