#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

int getFirstMath(const string s, const string r) {
    //
}

int main(void) {
    string str;
    cin >> str;
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    int first = getFirstMatch(str, reversed);
    cout << first << endl;
    cout  << string(str.begin(), str.begin() + first) << reversed << endl;
    return 0;
}