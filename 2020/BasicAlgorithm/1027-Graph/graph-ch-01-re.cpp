#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int order[100001];
int prev_of[100001]; // prev == 0 : uncheck

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
        cin >> order[i];

    prev_of[1] = -1; // dummy

    for (int i = 0, idx = 1; i < n; i++) {
        int cur = order[i];

        int next_count = 0;
        for (int next : graph[cur]) {
            if (prev_of[next] != 0) continue;
            prev_of[next] = cur;
            next_count++;
        }

        for (int j = idx; j < idx + next_count; j++) {
            if (prev_of[order[j]] == cur) continue;
            cout << false;
            return 0;
        }

        idx += next_count;
    }

    cout << true;
    return 0;
}