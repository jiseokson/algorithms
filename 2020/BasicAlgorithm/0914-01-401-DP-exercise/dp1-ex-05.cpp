#include <iostream>
using namespace std;

enum {UP, DOWN, NONE};

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxp(int d[][3], int cost[][2], int fs, int i) // top - down
{
    if (i < 0)
        return 0;
    if (d[i][fs] != 0)
        return d[i][fs];

    int res = 0;
    switch (fs) {
    case UP:
        res = max( cost[i][DOWN] + maxp(d, cost, DOWN, i - 1), maxp(d, cost, NONE, i - 1) );
        break;
    case DOWN:
        res = max( cost[i][UP] + maxp(d, cost, UP, i - 1), maxp(d, cost, NONE, i - 1) );
        break;
    case NONE:
        res = cost[i][UP] + maxp(d, cost, UP, i - 1);
        res = max(res, cost[i][DOWN] + maxp(d, cost, DOWN, i - 1));
        res = max(res, maxp(d, cost, NONE, i - 1));
        break;
    }

    d[i][fs] = res;
    return res;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int d[n + 1][3] = {0};
        int cost[n][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                int p;
                cin >> p;
                cost[j][i] = p;
            }
        }

        int ans = cost[n - 1][UP] + maxp(d, cost, UP, n - 2);
        ans = max(ans, cost[n - 1][DOWN] + maxp(d, cost, DOWN, n - 2));
        ans = max(ans, maxp(d, cost, NONE, n - 2));
        cout << ans << '\n';
    }

    return 0;
}