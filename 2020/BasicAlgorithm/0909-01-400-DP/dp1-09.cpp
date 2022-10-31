#include <iostream>
using namespace std;

long long memo[2][100] = {0};

long long bcs(int m, int n)
{
    if (n == 0)
        return 1;
    if (memo[m][n] != 0)
        return memo[m][n];

    if (m == 1) {
        memo[m][n] = bcs(0, n - 1);
    } else {
        memo[m][n] = bcs(0, n - 1) + bcs(1, n - 1);
    }
    return memo[m][n];
}

int main(void)
{
    int n;
    cin >> n;
    cout << bcs(1, n - 1);
    return 0;
}