#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main(void) {
    int a, b;
    cin >> a >> b;
    cout << "gcd: " << gcd(a, b) << '\n';
    cout << "lcm: " << lcm(a, b) << '\n';
    return 0;
}