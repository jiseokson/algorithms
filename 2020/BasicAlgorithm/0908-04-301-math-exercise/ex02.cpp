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
    int n, s;
    cin >> n >> s;

    int * dl = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dl[i] = s < a ? a - s : s - a;
    }

    if (n == 1) {
        cout << dl[0];
        delete []dl;
        return 0;
    }

    int ans = gcd(dl[0], dl[1]);
    for (int i = 2; i < n; i++) {
        ans = gcd(ans , dl[i]);
    }

    cout << ans;

    delete []dl;
    return 0;
}