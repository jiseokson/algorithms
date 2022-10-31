#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[3001];
bool cycle[3001];

int check_cycle(int prev, int cur)
{
    static bool visited[3001] = {false};

    for (int next : graph[cur]) {
        if (next == prev) continue;

        if (visited[next]) { // cycle이 되는 노드 확인
            cycle[cur] = true;
            return next;
        }

        visited[next] = true;
        int res = check_cycle(cur, next);

        if (res > 0) {
            cycle[cur] = true;
            if (res != cur) return res; // 아직 사이클인 노드 체크 중
            return -1; // 사이클인 노드 체크 완료
        } else if (res == -1) {
            return -1;
        }
    }

    return 0; // 이 경로로는 더이상 사이클을 찾을 수 없는 경우(마지막 노드)
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    check_cycle(0, 1);

    queue<int> q;
    int dist[3001] = {0};

    for (int i = 1; i <= n; i++) {
        if (cycle[i]) q.push(i);
        else dist[i] = -1;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (dist[next] >= 0) continue;
            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';

    return 0;
}