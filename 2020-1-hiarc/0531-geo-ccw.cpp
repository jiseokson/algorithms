#include <iostream>

using namespace std;

int main(void) {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int temp = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
    if (temp > 0) cout << 1;
    else if (temp < 0) cout << -1;
    else cout << 0;
    return 0;
}