#include <iostream>
using namespace std;

void cain(int m, int n, int x, int y)
{
    x--, y--;
    for (int i = x; i < m * n; i += m) {
        if (i % n == y) {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cain(m, n, x, y);
    }

    return 0;
}