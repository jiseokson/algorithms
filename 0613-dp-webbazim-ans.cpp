#include <iostream>
#include <algorithm>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

// var:
// E: 최초에 입력받은 가격판
// digit: 가격판에 존재하는 모든 숫자(중복 가능, 정렬)
int c, m, n;
string e;
vi E, digit;
vvvi dp;

int solve(int i, bool less, int mod, int check) {
    // i: 현재 선택할 인덱스
    // less: 이전까지 선택된 숫자가 최초의 E보다 작은지 여부
    // mod: 이후 선택에서의 mod m
    // check: 이전까지 선택된 숫자의 집합

    if (i == n)
        return less && mod == 0;

    int &ret = dp[less][mod][check];
    if (ret != -1) return ret;

    ret = 0;
    for (int j = 0; j < n; ++j) {
        if (
            (check & (1 << j)) ||
            j > 0 && digit[j - 1] == digit[j] && (~check & (1 << (j - 1)))
        ) continue;
        int next_mod = (mod * 10 + digit[j]) % m;
        if (less)
            ret += solve(i + 1, true, next_mod, check + (1 << j));
        else if (E[i] >= digit[j])
            ret += solve(i + 1, E[i] > digit[j], next_mod, check + (1 << j));
        ret %= MOD;
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        cin >> e >> m;
        n = e.length();

        E = vi();
        for (char d: e) E.push_back(d - '0');

        digit = vi(E.begin(), E.end());
        sort(digit.begin(), digit.end());

        dp = vvvi(2, vvi(m, vi(1 << n, -1)));
        cout << solve(0, false, 0, 0) << '\n';
    }

    return 0;
}