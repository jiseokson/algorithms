#include <iostream>
using namespace std;

int memo[201][201];

int sumdecomp(int n, int k)
{
    if (k == 1)
        return 1;
    if (memo[n][k] != 0)
        return memo[n][k];

    int res = 0;
    for (int i = 0; i <= n && k - 1 >= 1; i++)
        res = (res + sumdecomp(n - i, k - 1) % 1000000000) % 1000000000;
    
    memo[n][k] = res;
    return memo[n][k];
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    cout << sumdecomp(n, k);
    return 0;
}