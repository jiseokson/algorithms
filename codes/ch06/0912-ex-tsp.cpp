#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vi visited;
vvi dist;

int shortest_path_dist(int here, int dist_sum, int count) {
    if (count == n)
        return dist_sum + dist[here][0];
    int ret = INF;
    for (int next = 0; next < n; ++next) {
        if (visited[next]) continue;
        visited[next] = 1;
        ret = min(
            ret,
            shortest_path_dist(next, dist_sum + dist[here][next], count + 1)
        );
        visited[next] = 0;
    }
    return ret;
}

int main(void) {
    cin >> n;
    visited = vi(n, 0);
    dist = vvi(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d;
            cin >> d;
            dist[i][j] = d;
        }
    }
    visited[0] = 1;
    cout << shortest_path_dist(0, 0, 1);
    return 0;
}

// 4
// 0 10 8 13
// 10 0 15 7
// 8 15 0 12
// 13 7 12 0