#include <iostream>
using namespace std;

int memo[1001] = {0};

int ans(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (memo[n] != 0)
        return memo[n];

    memo[n] = (ans(n - 1) % 10007 + ans(n - 2) % 10007) % 10007;
    return memo[n];
}

int main(void)
{
    int n;
    cin >> n;
    cout << ans(n);
    return 0;
}