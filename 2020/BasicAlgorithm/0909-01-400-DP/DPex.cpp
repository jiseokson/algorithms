#include <iostream>
using namespace std;

int fibo1(int n)
{
    static int memo[1000] = {0};
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        if (memo[n] == 0) {
            memo[n] = fibo1(n - 1) + fibo1(n - 2);
        }
        return memo[n];
    }
}

int fibo2(int n)
{
    int f[1000] = {0, 1};
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(void)
{
    for (int i = 0; i <= 10; i++) {
        cout << fibo1(i) << endl;
    }
    cout << endl;
    for (int i = 0; i <= 10; i++) {
        cout << fibo2(i) << endl;
    }
    return 0;
}