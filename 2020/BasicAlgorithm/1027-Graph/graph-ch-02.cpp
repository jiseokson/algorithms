#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[100001];
int visit_order[100001];
bool visited[100001];
int prev_node[100001];

void dfs(int prev, int cur)
{
    prev_node[cur] = prev;

    for (int next : graph[cur]) {
        if (visited[next]) continue;
        visited[next] = true;
        dfs(cur, next);
    }
}

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

    dfs(0, 1);

    stack<int> s;
    s.push(1);

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top() != prev_node[visit_order[i]]) s.pop();
        if (s.empty()) {
            cout << false;
            return 0;
        }
        s.push(visit_order[i]);
    }

    cout << true;
    return 0;
}