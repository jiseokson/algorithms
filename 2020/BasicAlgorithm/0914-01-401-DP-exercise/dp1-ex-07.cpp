#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int triangle[n][n];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            int a;
            cin >> a;
            triangle[row][col] = a;
        }
    }

    for (int row = n - 1; row > 0; row--) {
        for (int col = 0; col < row; col++) {
            triangle[row - 1][col] += max(triangle[row][col], triangle[row][col + 1]);
        }
    }

    cout << triangle[0][0];
    return 0;
}