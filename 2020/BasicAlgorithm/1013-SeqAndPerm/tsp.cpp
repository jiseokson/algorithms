#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int cost[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    int traverse[n];
    for (int i = 0; i < n; i++)
        traverse[i] = i;

    int ans = 10 * 1000000;
    do {
        int c = 0;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (cost[traverse[i]][traverse[i + 1]] == 0) {
                ok = false;
                break;
            }
            c += cost[traverse[i]][traverse[i + 1]];
        }
        if (ok && cost[traverse[n - 1]][traverse[0]] != 0) {
            c += cost[traverse[n - 1]][traverse[0]];
            ans = min(ans, c);
        }
    } while (next_permutation(traverse + 1, traverse + n)); // 시작점 고정

    cout << ans;

    return 0;
}