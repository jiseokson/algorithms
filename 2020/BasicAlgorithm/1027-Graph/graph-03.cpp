#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> adj_list[n + 1];
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }

    int components_count = 0;
    queue<int> q;
    bool visited[n + 1] = {false};

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : adj_list[cur]) {
                if (visited[next] == false) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        components_count++;
    }

    cout << components_count;
    return 0;
}