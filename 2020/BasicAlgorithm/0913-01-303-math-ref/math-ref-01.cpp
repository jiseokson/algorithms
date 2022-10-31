#include <iostream>
using namespace std;

char to_unit(int a)
{
    if (a >= 10) {
        return 'A' + a - 10;
    } else {
        return '0' + a;
    }
}

int main(void)
{
    int n, b;
    cin >> n >> b;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    string ans = "";
    while (n > 0) {
        ans = to_unit(n % b) + ans;
        n /= b;
    }
    cout << ans;
    return 0;
}