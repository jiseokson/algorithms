#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a < b) {
        int t = a;
        a = b, b = t;
    }

    while (b != 0) {
        int r = a % b;
        a = b, b = r;
    }

    return a;
}

int main(void)
{
    int il[100];
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long ans = 0; // 이거
        cin >> n;

        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            il[i] = nn;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(il[i], il[j]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}