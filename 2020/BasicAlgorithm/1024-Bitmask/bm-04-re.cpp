#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    int arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%1d", &arr[i][j]);
    }

    for (int bm = 0; bm < (1 << (m * n)); bm++) {
        //
    }
}