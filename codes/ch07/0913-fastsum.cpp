#include <iostream>

using namespace std;

int fastsum(int n) {
    if (n == 1) return 1;
    if (n % 2 == 1) return n + fastsum(n - 1);
    return 2 * fastsum(n / 2) + (n * n / 4);
}

int main(void) {
    for (int i = 1; i <= 10; ++i)
        cout << i << ": " << fastsum(i) << '\n';
    return 0;
}