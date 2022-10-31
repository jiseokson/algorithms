#include <iostream>
using namespace std;

int d[1000001];

int pn(int n)
{
    if (n == 0)
        return 1;
    if (d[n] != 0)
        return d[n];

    int res = 0;
    for (int i = 1; i <= 3 && n - i >= 0; i++)
        res = (res + pn(n - i) % 1000000009) % 1000000009;

    d[n] = res;
    return d[n];
}

int main(void)
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << pn(n) << '\n';
    }

    return 0;
}