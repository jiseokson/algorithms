#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
#define NODE first
#define WEIGHT second

int main(void)
{
    int n;
    vector<edge> graph[10001];

    queue<int> q;
    int dist[10001] = {0};

    int u, max_dist = 0;
    int radius = 0;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (max_dist < dist[cur]) {
            max_dist = dist[cur];
            u = cur;
        }

        for (edge next : graph[cur]) {
            if (dist[next.NODE] > 0 || next.NODE == 1) continue;
            q.push(next.NODE);
            dist[next.NODE] = dist[cur] + next.WEIGHT;
        }
    }

    memset(dist, 0, sizeof(dist));
    q.push(u);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        radius = max(radius, dist[cur]);

        for (edge next : graph[cur]) {
            if (dist[next.NODE] > 0 || next.NODE == u) continue;
            q.push(next.NODE);
            dist[next.NODE] = dist[cur] + next.WEIGHT;
        }
    }

    cout << radius;

    return 0;
}