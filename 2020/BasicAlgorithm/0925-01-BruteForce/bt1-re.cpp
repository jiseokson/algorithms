#include <iostream>
using namespace std;

int n;
char candy[50][50];

inline void swap(char& c1, char& c2)
{
    char t = c1;
    c1 = c2, c2 = t;
}

int count(int i, int j)
{
    int rowRes = 0, colRes = 0;
    int rowCount = 1, colCount = 1;
    for (int k = 1; k < n; k++) {
        if (candy[i][k] == candy[i][k - 1])
            rowCount++;
        else
            rowCount = 1;
        if (rowRes < rowCount)
            rowRes = rowCount;

        if (candy[k][j] == candy[k - 1][j])
            colCount++;
        else
            colCount = 1;
        if (colRes < colCount)
            colRes = colCount;
    }

    return rowRes > colRes ? rowRes : colRes;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
            candy[i][j] = row[j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = 0;
            if (i + 1 < n) {
                swap(candy[i][j], candy[i + 1][j]);
                temp = max(count(i, j), count(i + 1, j));
                swap(candy[i][j], candy[i + 1][j]);
            }
            if (j + 1 < n) {
                swap(candy[i][j], candy[i][j + 1]);
                temp = max( temp, max(count(i, j), count(i, j + 1)) );
                swap(candy[i][j], candy[i][j + 1]);
            }

            if (ans < temp)
                ans = temp;
        }
    }

    cout << ans;
    return 0;
}