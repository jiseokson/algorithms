#include <iostream>

using namespace std;

int c, n, p, l;
string X = "X+YF";
string Y = "FX-Y";

string dragon(int g) {
    if (g == 0) return "FX";
    string temp = dragon(g - 1);
    string ret = "";
    for (char c : temp) {
        if (c == 'X') ret += X;
        else if (c == 'Y') ret += Y;
        else ret += c;
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        cin >> n >> p >> l;
        cout << dragon(n).substr(p - 1, l) << '\n';
    }

    return 0;
}
