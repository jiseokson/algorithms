#include <iostream>
using namespace std;


int main(void)
{
    string str;
    cin >> str;

    if (str.length() % 3 == 1) {
        str = "00" + str;
    } else if (str.length() % 3 == 2) {
        str = "0" + str;
    }

    string ans;
    for (int i = 0; i < str.length(); i += 3) {
        bool d1 = str[i] == '0' ? 0 : 1;
        bool d2 = str[i + 1] == '0' ? 0 : 1;
        bool d3 = str[i + 2] == '0' ? 0 : 1;
        ans += to_string(4 * d1 + 2 * d2 + 1 * d3);
    }

    cout << ans;
    return 0;
}