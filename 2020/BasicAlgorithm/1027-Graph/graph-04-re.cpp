#include <iostream>
#include <vector>
using namespace std;

enum {R = 1, B = 2};

inline int next_color(int c) { return 3 - c; }

bool is_bipartite_graph(vector<int> (&adj_list)[20001], int color[], int cur, int cur_color)
{
    color[cur] = cur_color;

    for (int next : adj_list[cur]) {
        if (color[next]) {
            if (color[cur] == color[next])
                return false;
        } else {
            if (is_bipartite_graph(adj_list, color, next, next_color(cur_color)) == false)
                return false;
        }
    }

    return true;
}

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

        bool ok = true;
        int color[20001] = {0};

        for (int i = 1; i <= v; i++) {
            if (color[i]) continue;

            color[i] = R;
            if (is_bipartite_graph(adj_list, color, i, R) == false) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}