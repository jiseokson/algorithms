#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj_list[1100];

void dfs(int cur)
{
    static bool visited_dfs[1100] = {false};
    visited_dfs[cur] = true;
    cout << cur << ' ';

    for (int i : adj_list[cur])
        if (visited_dfs[i] == false) dfs(i);
}

int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
        sort(adj_list[i].begin(), adj_list[i].end());

    dfs(v);
    cout << '\n';

    queue<int> q;
    bool visited_bfs[1100] = {false};

    visited_bfs[v] = true;
    q.push(v);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << ' ' ;

        for (int i : adj_list[cur]) {
            if (visited_bfs[i] == false) {
                visited_bfs[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
} 