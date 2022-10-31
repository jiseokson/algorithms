#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool check[100001];
int parent[100001];

void make_tree(int cur_parent, int cur)
{
    parent[cur] = cur_parent;

    for (int next : graph[cur]) {
        if (check[next] == false) {
            check[next] = true;
            make_tree(cur, next);
        }
    }
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    make_tree(0, 1);

    for (int cur = 2; cur <= n; cur++)
        cout << parent[cur] << '\n';

    return 0;
}