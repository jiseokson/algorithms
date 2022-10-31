#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> tree[100001]; // first : vertex, second : weight

int main(void)
{
    int v;
    cin >> v;

    for (int i = 0; i < v; i++) {
        int cur;
        cin >> cur;
        while (true) {
            int v, w;
            cin >> v;
            if (v == -1) break;
            cin >> w;
            tree[cur].push_back(make_pair(v, w));
        }
    }

    int u, max_dist = 0;
    queue<pair<int, int>> q; // first : vertex, second : dist
    bool check1[100001] = {false};

    q.push(make_pair(1, 0));
    check1[1] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (max_dist < cur.second) {
            u = cur.first;
            max_dist = cur.second;
        }

        for (pair<int, int> next : tree[cur.first]) {
            if (check1[next.first]) continue;
            q.push(make_pair(next.first, cur.second + next.second));
            check1[next.first] = true;
        }
    }

    int radius = 0;
    bool check2[100001] = {false};

    q.push(make_pair(u, 0));
    check2[u] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        if (radius < cur.second) {
            radius = cur.second;
        }

        for (pair<int, int> next : tree[cur.first]) {
            if (check2[next.first]) continue;
            q.push(make_pair(next.first, cur.second + next.second));
            check2[next.first] = true;
        }
    }

    cout << radius;

    return 0;
}