#include <iostream>
using namespace std;

int memo[1000001] = {0};
int ans(int n)
{
    if (n == 1) // 1
        return 1;
    if (n == 2) // 2, 1 + 1
        return 2;
    if (n == 3) // 3, 2 + 1, 1 + 1 + 1
        return 4;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = ans(n - 1) + ans(n - 2) + ans(n - 3);
    return memo[n];
}

int main(void)
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << ans(n) << '\n';
    }

    return 0;
}