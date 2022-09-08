#include <iostream>
#include <vector>

#define INF 1000000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vvi dist;
vvi dp;

int shortest(int cur, int visited) {
    if (visited == (1 << n) - 1) return dist[cur][0];
    int &ret = dp[cur][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int next = 0; next < n; ++next) {
        if (visited & (1 << next)) continue;
        ret = min(ret, dist[cur][next] + shortest(next, visited + (1 << next)));
    }
    return ret;
}

int main(void) {
    cin >> n;
    dist = vvi(n, vi(n));
    dp = vvi(n, vi(1 << n, -1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];
    cout << shortest(0, 1) << '\n';
    return 0;
}