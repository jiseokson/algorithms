#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct SuffixComparator {
    const string &str;
    SuffixComparator(const string &str): str(str) {}
    bool operator()(int a, int b) {
        return strcmp(str.c_str() + a, str.c_str() + b) < 0;
    }
};

vi getSuffixArrayNaive(const string &str) {
    vi sa;
    for (int i = 0; i < str.length(); ++i) sa.push_back(i);
    sort(sa.begin(), sa.end(), SuffixComparator(str));
    return sa;
}

int main(void) {
    string str;
    cin >> str;
    vi sa = getSuffixArrayNaive(str);
    for (int i = 0; i < sa.size(); ++i)
        cout << sa[i] << '\n';
    return 0;
}