#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool a[2000][2000]; // 인접행렬
vector<int> g[2000]; // 인접리스트
vector<pair<int, int>> edges; // 간선리스트

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)  {
        int from, to;
        cin >> from >> to;

        // 인접행렬 추가
        a[from][to] = true;
        a[to][from] = true;

        // 인접리스트
        g[from].push_back(to);
        g[to].push_back(from);

        // 간선 리스트 추가
        edges.push_back(make_pair(from, to));
        edges.push_back(make_pair(to, from));
    }

    m *= 2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // A -> B
            int A = edges[i].first;
            int B = edges[i].second;

            // C -> D
            int C = edges[j].first;
            int D = edges[j].second;

            if (A == B || A == C || A == D || B == C || B == D || C == D)
                continue;

            // B -> C
            if (!a[B][C]) continue;

            // D -> E
            for (int E : g[D]) {
                if (A == E || B == E || C == E || D == E)
                    continue;
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}