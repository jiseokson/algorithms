#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0)
            ans /= 10;
    }
    cout << ans % 10;
    return 0;
}