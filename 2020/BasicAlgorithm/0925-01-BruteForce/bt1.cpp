#include <iostream>
using namespace std;

char candy[50][50];

void swap(char& a, char& b)
{
    char t = a;
    a = b, b = t;
}

int count(int n, int row, int col)
{
    char c = candy[row][col];
    int rowUpper = 0, rowLower = 0;
    int colUpper = 0, colLower = 0;

    while (row + rowUpper + 1 < n  && c == candy[row + rowUpper + 1][col]) rowUpper++;
    while (row - rowLower - 1 >= 0 && c == candy[row - rowLower - 1][col]) rowLower++;
    while (col + colUpper + 1 < n  && c == candy[row][col + colUpper + 1]) colUpper++;
    while (col - colLower - 1 >= 0 && c == candy[row][col - colLower - 1]) colLower++;

    return max(rowUpper + rowLower, colUpper + colLower) + 1;
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            candy[i][j] = row[j];
        }
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int a;

            swap(candy[i][j], candy[i][j + 1]);
            a = max( count(n, i, j), count(n, i, j + 1) );
            if (ans < a)
                ans = a;
            swap(candy[i][j], candy[i][j + 1]);

            swap(candy[i][j], candy[i + 1][j]);
            a = max( count(n, i, j), count(n, i + 1, j) );
            if (ans < a)
                ans = a;
            swap(candy[i][j], candy[i + 1][j]);
        }
    }

    for (int j = 0; j < n - 1; j++) {
        swap(candy[n - 1][j], candy[n - 1][j + 1]);
        int a = max( count(n, n - 1, j), count(n, n - 1, j + 1) );
        if (ans < a)
            ans = a;
        swap(candy[n - 1][j], candy[n - 1][j + 1]);
    }

    cout << ans;
    return 0;
}