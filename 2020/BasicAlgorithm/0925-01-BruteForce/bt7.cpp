#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 9, len = 1; ; i = i * 10 + 9, len++) {
        if (n > i) {
            ans += len * ((i + 1) / 10 * 9);
        } else {
            ans += len * (n - i / 10);
            cout << ans;
            return 0;
        }
    }
}