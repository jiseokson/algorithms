#include <iostream>
using namespace std;

int n;
int stats[30][30];
int start[30];
int link[30];

int mingap(int startIndex, int linkIndex, int select)
{
    if (startIndex + linkIndex == n) {
        int startStats = 0;
        for (int i = 0; i < startIndex - 1; i++) {
            for (int j = i + 1; j < startIndex; j++)
                startStats += stats[start[i]][start[j]] + stats[start[j]][start[i]];
        }

        int linkStats = 0;
        for (int i = 0; i < linkIndex - 1; i++) {
            for (int j = i + 1; j < linkIndex; j++)
                linkStats += stats[link[i]][link[j]] + stats[link[j]][link[i]];
        }

        return abs(startStats - linkStats);
    }
    
    if (select > n)
        return INT32_MAX;

    start[startIndex] = select;
    int res = mingap(startIndex + 1, linkIndex, select + 1);

    link[linkIndex] = select;
    return min(res, mingap(startIndex, linkIndex + 1, select + 1));
}

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> stats[i][j];
    }
    cout << mingap(0, 0, 1);
    return 0;
}