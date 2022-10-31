#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int visit_order[100001];

queue<int> q;
bool check[100001];
int prev_node[100001];

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++)
        cin >> visit_order[i];

    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (check[next]) continue;
            q.push(next);
            check[next] = true;
            prev_node[next] = cur;
        }
    }

    for (int i = 1, idx = 0; i < n; i++) {
        while (idx < n && !(prev_node[visit_order[i]] == visit_order[idx])) idx++;
        if (idx == n) {
            cout << false;
            return 0;
        }
    }

    cout << true;
    return 0;
}