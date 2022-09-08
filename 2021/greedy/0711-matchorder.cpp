#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        vi other(n), our(n);
        for (int i = 0; i < n; ++i) cin >> other[i];
        for (int i = 0; i < n; ++i) cin >> our[i];

        sort(other.begin(), other.end());
        sort(our.begin(), our.end());

        int ans = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j < n && other[i] > our[j]) ++j;
            if (j < n) {
                ++ans;
                ++j;
            }
            ++i;
        }

        cout << ans << '\n';
    }

    return 0;
}