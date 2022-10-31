#include <iostream>
using namespace std;

int n;
int stats[30][30];
int start[20];
int link[20];

int mingap(int index, int target)
{
    if (index >= (n / 2)) {
        for (int i = 1, linkIndex = 0; i <= n && linkIndex < (n / 2); i++) {
            bool ok = true;
            for (int j = 0; j < (n / 2); j++) {
                if (start[j] == i) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                link[linkIndex++] = i;
        }

        int startStats = 0;
        int linkStats = 0;
        for (int i = 0; i < (n / 2) - 1; i++) {
            for (int j = i + 1; j < (n / 2); j++) {
                startStats += stats[start[i]][start[j]] + stats[start[j]][start[i]];
                linkStats += stats[link[i]][link[j]] + stats[link[j]][link[i]];
            }
        }

        return abs(startStats - linkStats);
    }
    if (target > n)
        return INT32_MAX;

    start[index] = target;
    int res = mingap(index + 1, target + 1);
    return min(res, mingap(index, target + 1));
}

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> stats[i][j];
    }
    cout << mingap(0, 1);
    return 0;
}