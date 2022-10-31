#include <iostream>
using namespace std;

int memo[1000001] = {0};

int minop(int n) // Top - down
{
    if (n == 1)
        return 0;

    if (memo[n] != 0)
        return memo[n];

    int res = 1 + minop(n - 1);

    if (n % 3 == 0) {
        int nres = 1 + minop(n / 3);
        if (res > nres) {
            res = nres;
        }
    }

    if (n % 2 == 0) {
        int nres = 1 + minop(n / 2);
        if (res > nres) {
            res = nres;
        }
    }

    memo[n] = res;
    return res;
}

int main(void)
{
    int n;
    cin >> n;
    cout << minop(n);
    return 0;
}