#include <iostream>
using namespace std;

int n;
char signs[15][15];
int arr[15];
int accu_sum[15] = {0};

inline bool check_sign(int n, int i, int j)
{
    switch (signs[i][j]) {
    case '+':
        return n > 0;
    case '-':
        return n < 0;
    case '0':
        return n == 0;
    }
}

bool func(int index)
{
    if (index > n) {
        for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
        cout << '\n';
        return true;
    }

    for (int i = -10; i <= 10; i++) {
        bool ok = true;
        for (int j = 1; j <= index; j++) {
            if(!check_sign(accu_sum[index - 1] - accu_sum[j - 1] + i, j, index)) {
                ok = false;
                break;
            }
        }

        if (ok) {
            arr[index] = i;
            accu_sum[index] = accu_sum[index - 1] + i;
            if (func(index + 1)) return true;
        }
    }

    return false;
}

int main(void)
{
    string signs_str;
    cin >> n >> signs_str;

    for (int i = 1, si = 0; i <= n; i++) {
        for (int j = i; j <= n; j++)
            signs[i][j] = signs_str[si++];
    }

    func(1);

    return 0;
}