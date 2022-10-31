#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int d[2][n + 1];
        memset(d, 0, 2 * (n + 1) * sizeof(int));

        for (int row = 0; row < 2; row++) {
            for (int col = 1; col <= n; col++) {
                int s;
                cin >> s;
                d[row][col] = s;
            }
        }

        for (int i = 2; i <= n; i++) {
            d[0][i] += max(max(d[1][i - 1], d[1][i - 2]), d[0][i - 2]);
            d[1][i] += max(max(d[0][i - 1], d[0][i - 2]), d[1][i - 2]);
        }

        cout << max(max(d[0][n], d[1][n]), max(d[0][n - 1], d[1][n - 1])) << '\n';
    }
    return 0;
}