#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int c, n;
string wildcard, filename;
vvi cache;

// int match(int i, int j) {
//     if (i == wildcard.length() && j == filename.length())
//         return 1;
//     if (i == wildcard.length() || j == filename.length())
//         return 0;


//     int& ret = cache[i][j];
//     if (ret != -1) return ret;

//     if (wildcard[i] == '?')
//         return ret = match(i + 1, j + 1);
//     if (wildcard[i] != '*')
//         return ret = (wildcard[i] == filename[j]? match(i + 1, j + 1): 0);
//     return ret = match(i, j + 1) || match(i + 1, j);
// }

int match(int i, int j) {
    int& ret = cache[i][j];
    if (ret != -1) return ret;

    if (i == wildcard.length()) return ret = (j == filename.length());
    if (i < wildcard.length() && j < filename.length() && (wildcard[i] == '?' || wildcard[i] == filename[j]))
        return ret = match(i + 1, j + 1);
    if (wildcard[i] == '*') return ret = match(i + 1, j) || (j < filename.length() && match(i, j + 1));
    return ret = 0;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> wildcard >> n;
        vs matches;
        for (int i = 0; i < n; ++i) {
            cin >> filename;
            // cache = vvi(wildcard.length() + 1, vi(filename.length() + 1, -1));
            cache = vvi(250, vi(250, -1));
            if (match(0, 0)) matches.push_back(filename);
        }
        sort(matches.begin(), matches.end());
        for (int i = 0; i < matches.size(); ++i)
            cout << matches[i] << '\n';
    }

    return 0;
}