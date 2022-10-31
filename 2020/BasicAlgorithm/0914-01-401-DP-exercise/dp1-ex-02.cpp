#include <iostream>
using namespace std;

enum {R, G, B};
int d[3][1001];

int mincost(int cost[][3], int fc, int i)
{
    if (i < 0)
        return 0;
    if (d[fc][i] != 0)
        return d[fc][i];

    int res = 0;
    switch (fc) {
    case R:
        res = min( cost[i][G] + mincost(cost, G, i - 1),
                   cost[i][B] + mincost(cost, B, i - 1) );
        break;
    case G:
        res = min( cost[i][R] + mincost(cost, R, i - 1),
                   cost[i][B] + mincost(cost, B, i - 1) );
        break;
    case B:
        res = min( cost[i][R] + mincost(cost, R, i - 1),
                   cost[i][G] + mincost(cost, G, i - 1) );
        break;
    }

    d[fc][i] = res;
    return res;
}

int main(void)
{
    int n;
    cin >> n;

    int cost[n][3];
    for (int i = 0; i < n; i++) {
        int rc, gc, bc;
        cin >> rc >> gc >> bc;
        cost[i][R] = rc;
        cost[i][G] = gc;
        cost[i][B] = bc;
    }

    int ans = min( cost[n - 1][R] + mincost(cost, R, n - 2),
                   cost[n - 1][G] + mincost(cost, G, n - 2) );
    ans = min(ans, cost[n - 1][B] + mincost(cost, B, n - 2));
    cout << ans;
    return 0;
}