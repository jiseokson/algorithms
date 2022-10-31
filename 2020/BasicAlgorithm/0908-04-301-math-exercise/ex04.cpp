#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    string on;
    string bn = "";
    cin >> on;

    while (!on.empty()) {
        int u = (int)on.back() - '0';
        on.pop_back();
        bn += to_string(u % 2), u /= 2;
        bn += to_string(u % 2), u /= 2;
        bn += to_string(u % 2), u /= 2;
    }

    while (!bn.empty() && bn.back() == '0') {
        bn.pop_back();
    }

    if (bn.empty()) {
        cout << 0;
        return 0;
    }

    for (int i = bn.length() - 1; i >= 0; i--) {
        cout << (bn[i]);
    }
    return 0;
}