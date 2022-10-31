#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<int> adj_list[20001];
        for (int i = 0; i < e; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }

        queue<int> q;
        bool visited[20001] = {false};
        bool set[20001] = {false};
        bool set_check[20001] = {false};
        bool cur_set = 0;
        bool is_bin_graph = true;

        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            set[i] = !cur_set;
            q.push(i);

            while (!q.empty()) {
                int cur = q.front();
                cur_set = set[cur];
                q.pop();

                // cout << "cur = " << cur << ' ' << (set[cur] ? 'R' : 'B') << '\n'; // deb

                for (int next : adj_list[cur]) {
                    // cout << "    check " << next << " = " << visited[next] << '\n'; // deb

                    if (visited[next]) {
                        if (set[next] == set[cur]) {
                            is_bin_graph = false;
                            while (!q.empty()) q.pop();
                            break;
                        } else continue;
                    } else {
                        visited[next] = true;
                        set[next] = !cur_set;
                        q.push(next);
                    }
                }
            }
            
            if (is_bin_graph == false) break;
        }

        if (is_bin_graph) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}