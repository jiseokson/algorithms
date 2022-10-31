#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    int len;

    cin >> a >> b;
    cin >> len;

    int an[len];
    for (int i = 0; i < len; i++) {
        int u;
        cin >> u;
        an[i] = u;
    }

    if (len == 1 && an[0] == 0) {
        cout << 0;
        return 0;
    }

    int n = 0;
    for (int u : an) {
        n = n * a + u;
    }

    string ans = "";
    while (n > 0) {
        ans = to_string(n % b) + " " + ans;
        n /= b;
    }
    cout << ans;

    return 0;
}