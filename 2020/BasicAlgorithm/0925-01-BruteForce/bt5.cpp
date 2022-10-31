#include <iostream>
using namespace std;

enum {LEFT, RIGHT, UP, DOWN, NONE};

int n, m;
int ns[500][500];

int tetromino1(int i, int j, int dir, int len)
{
    if (len == 0)
        return 0;

    int temp = 0;
    if (dir != RIGHT && i + 1 < n) {
        temp = max(temp, tetromino1(i + 1, j, LEFT, len - 1));
    }
    if (dir != LEFT && 0 <= i - 1) {
        temp = max(temp, tetromino1(i - 1, j, RIGHT, len - 1));
    }
    if (dir != DOWN && j + 1 < m) {
        temp = max(temp, tetromino1(i, j + 1, UP, len - 1));
    }
    if (dir != UP && 0 <= j - 1) {
        temp = max(temp, tetromino1(i, j - 1, DOWN, len - 1));
    }

    return ns[i][j] + temp;
}

int tetromino2(int i, int j)
{
    int temp1 = 0, temp2 = 0;
    for (int k = 0; k < 3; k++) {
        temp1 += ns[i + k][j];
        temp2 += ns[i][j + k];
    }
    
    if (0 < j && j < m - 1) {
        temp1 += max(ns[i + 1][j + 1], ns[i + 1][j - 1]);
    } else if (j == 0) {
        temp1 += ns[i + 1][1];
    } else if (j == m - 1){
        temp1 += ns[i + 1][m - 2];
    }

    if (0 < i && i < n - 1) {
        temp2 += max(ns[i + 1][j + 1], ns[i - 1][j + 1]);
    } else if (i == 0) {
        temp2 += ns[1][j + 1];
    } else if (i = n - 1) {
        temp2 += ns[n - 2][j + 1];
    }
    
    return temp1 > temp2 ? temp1 : temp2;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int n;
            cin >> n;
            ns[i][j] = n;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = tetromino1(i, j, NONE, 4);
            if (ans < temp)
                ans = temp;
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int temp = tetromino2(i, j);
            if (ans < temp)
                ans = temp;
        }
    }

    cout << ans;
    return 0;
}