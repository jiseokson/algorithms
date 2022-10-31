#include <iostream>
using namespace std;

int main(void)
{
    bool ef[1000001] = {false, false, false};
    for (long long i = 2; i <= 1000000; i++) {
        if (ef[i] == false) {
            for (long long  j = i * i; j <= 1000000; j += i) {
                ef[j] = true;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 0;
        int l = 2, r = n - 2;
        while (l <= r) {
            if (!ef[r]) {
                ans++;
            }

            do {
                l++;
            } while (ef[l]);
            r = n - l;
        }

        cout << ans <<'\n';
    }

    return 0;
}