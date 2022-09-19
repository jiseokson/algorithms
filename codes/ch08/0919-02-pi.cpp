#include <iostream>
#include <vector>
#include <algorithm>

#define INF (987654321)

using namespace std;

using vi = vector<int>;

int c;
string pi;
vi cache;

bool is_sequence(const vi& arr) {
    int delta = arr[1] - arr[0];
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i] - arr[i - 1] != delta) return false;
    return true;
}

bool is_alternately(const vi& arr) {
    // 정확한 구현
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] != arr[i % 2]) return false;
    return true;
}

bool is_monotonous(const vi& arr) {
    int delta = arr[1] - arr[0];
    return abs(delta) == 1 && is_sequence(arr);
}

bool is_all_same(const vi& arr) {
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i] != arr[0]) return false;
    return true;
}

int eval_difficulty(const string& piece) {
    vi arr(piece.length());
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = piece[i] - '0';

    if (is_all_same(arr)) return 1;
    else if (is_monotonous(arr)) return 2;
    else if (is_alternately(arr)) return 4;
    else if (is_sequence(arr)) return 5;
    else return 10;
}

int min_difficulty(int i) {
    if (i == pi.length()) return 0;
    int& ret = cache[i];
    if (ret != -1) return ret;

    ret = INF;
    for (int j = 3; j <= 5; ++j)
        if (i + j <= pi.length())
            ret = min(ret, eval_difficulty(pi.substr(i, j)) + min_difficulty(i + j));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> pi;
        cache = vi(pi.length() + 1, -1);
        cout << min_difficulty(0) << '\n';
    }

    return 0;
}