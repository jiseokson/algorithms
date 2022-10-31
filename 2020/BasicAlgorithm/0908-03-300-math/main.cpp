#include <iostream>
using namespace std;

long long c2(long long n)
{
    int res = 0;
    for (long long i = 2; i <= n; i *= 2) {
        res += n / i;
    }
    return res;
}

long long c5(long long n)
{
    int res = 0;
    for (long long i = 5; i <= n; i *= 5) {
        res += n / i;
    }
    return res;
}

int main(void)
{
    long long n, m;
    cin >> n >> m;

    int a = c2(n) - c2(m) - c2(n - m);
    int b = c5(n) - c5(m) - c5(n - m);
    cout << (a < b ? a : b);

    return 0;
}