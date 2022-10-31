#include <iostream>
#include <cstdio>
using namespace std;

int m, n;
int arr[5][5];
bool used[5][5] = {false};
int max_slice_num = 0;

void make_max_slice(int i, int j, int sum)
{
    for (; i < m; i++, j = 0) {
        for (; j < n; j++) {
            if (used[i][j]) continue;

            for (int k = i, new_sum = 0; ; k++) {
                if (k == m || used[k][j]) {
                    for (k--; i <= k; k--) used[k][j] = false;
                    break;
                }
                used[k][j] = true;
                new_sum = new_sum * 10 + arr[k][j];
                make_max_slice(i, j + 1, sum + new_sum);
            }

            for (int k = j, new_sum = 0; ; k++) {
                if (k == n || used[i][k]) {
                    for (k--; j <= k; k--) used[i][k] = false;
                    break;
                }
                used[i][k] = true;
                new_sum = new_sum * 10 + arr[i][k];
                make_max_slice(i, j + 1, sum + new_sum);
            }

            return;
        }
    }

    if (max_slice_num < sum)
        max_slice_num = sum;
}

int main(void)
{
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%1d", &arr[i][j]);
    }

    make_max_slice(0, 0, 0);
    cout << max_slice_num;

    return 0;
}