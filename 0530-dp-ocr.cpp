#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<int, string> mis;
typedef map<string, int> msi;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

int m, q, n;
mis wm;
msi im;
vd B;
vvd T, M;
vi clf;

vvd dp;
vd clf_prob_memo;
vvi sel;

inline double orig_prob(int i, int lw, int iw) {
    if (i > 0) return T[lw][iw];
    return B[iw];
}

inline double clf_orig_prob(int i, int iw) {
    return M[iw][clf[i]];
}

inline double clf_prob(int i) {
    double &ret = clf_prob_memo[i];
    if (ret != -1.0) return ret;
    ret = 0.0;
    for (int j = 0; j < m; ++j) ret += M[j][clf[i]];
    return ret;
}

inline double prob_i(int i, int lw, int iw) {
    return orig_prob(i, lw, iw) * clf_orig_prob(i, iw) / clf_prob(i);
}

double max_orig(int i, int lw) {
    if (i == n) return 1.0;

    double &ret = dp[i][lw];
    if (ret != -1.0) return ret;

    ret = 0.0;
    for (int iw = 0; iw < m; ++iw) {
        double temp = prob_i(i, lw, iw) * max_orig(i + 1, iw);
        if (ret < temp) {
            ret = temp;
            sel[i][lw] = iw;
        }
    }

    return ret;
}

void config_sel(int i, int lw) {
    if (i == n) {
        cout << '\n';
        return ;
    }
    cout << wm[sel[i][lw]] << ' ';
    config_sel(i + 1, sel[i][lw]);
}

void solve() {
    cin >> n;

    clf = vi(n);
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        clf[i] = im[word];
    }

    dp = vvd(n, vd(m, -1.0));
    clf_prob_memo = vd(n, -1.0);
    sel = vvi(n, vi(m, -1));

    max_orig(0, 0);
    config_sel(0, 0);
}

void get_input() {
    cin >> m >> q;

    B = vd(m);
    T = vvd(m, vd(m));
    M = vvd(m, vd(m));

    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        wm.insert({i, word});
        im.insert({word, i});
    }

    for (int i = 0; i < m; ++i)
        cin >> B[i];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> T[i][j];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> M[i][j];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    get_input();
    while (q--)
        solve();

    return 0;
}