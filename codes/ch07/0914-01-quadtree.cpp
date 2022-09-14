#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int c;
string picture;

int next(int i) {
    if (picture[i] != 'x') return i + 1;
    return next(next(next(next(i + 1))));
}

string reverse(int i) {
    if (picture[i] != 'x') return picture.substr(i, 1);
    int j1 = i + 1;
    int j2 = next(j1);
    int j3 = next(j2);
    int j4 = next(j3);
    return "x" + reverse(j3) + reverse(j4) + reverse(j1) + reverse(j2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> picture;
        cout << reverse(0) << '\n';
    }

    return 0;
}