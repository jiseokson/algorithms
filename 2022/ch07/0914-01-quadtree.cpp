#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

string reverse(string::iterator& i) {
    char head = *i++;
    if (head != 'x') return string(1, head);
    string upper_left = reverse(i);
    string upper_right = reverse(i);
    string lower_left = reverse(i);
    string lower_right = reverse(i);
    return string("x") + lower_left + lower_right + upper_left + upper_right;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> picture;
        // cout << reverse(0) << '\n';
        string::iterator i = picture.begin();
        cout << reverse(i);
    }

    return 0;
}