#include <iostream>
using namespace std;

int main(void)
{
    int n;
    string ans = "";
    
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    while (n != 0) {
        if (n < 0 && n % -2 != 0) {
            ans += to_string( -(n % -2) );
            n /= -2;
            n++;
        } else {
            ans += to_string(n % 2);
            n /= -2;
        }
    }

    for (int i = ans.length() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}