#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define NEGINF -1e200

using namespace std;

typedef vector<string> mis;
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
vvi sel;

inline double log_prob_i(int i, int lw, int iw) {
    return (i > 0 ? T[lw][iw] : B[iw]) + M[iw][clf[i]];
}

void config_sel(int i, int lw) {
    if (i == n) {
        cout << '\n';
        return ;
    }
    cout << wm[sel[i][lw]] << ' ';
    config_sel(i + 1, sel[i][lw]);
}

double max_orig(int i, int lw) {
    if (i == n) return 0.0;

    double &ret = dp[i][lw];
    if (ret != 1.0) return ret;

    ret = NEGINF;
    for (int iw = 0; iw < m; ++iw) {
        double temp = log_prob_i(i, lw, iw) + max_orig(i + 1, iw);
        if (ret < temp) {
            ret = temp;
            sel[i][lw] = iw;
        }
    }

    return ret;
}

void solve() {
    cin >> n;

    clf = vi(n);
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        clf[i] = im[word];
    }

    dp = vvd(n, vd(m, 1.0));
    sel = vvi(n, vi(m, -1));

    max_orig(0, 0);
    config_sel(0, 0);
}

void get_input() {
    cin >> m >> q;

    wm = mis(m);
    im = msi();
    B = vd(m);
    T = vvd(m, vd(m));
    M = vvd(m, vd(m));

    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        wm[i] = word;
        im[word] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
        B[i] = log(B[i]);
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> T[i][j];
            T[i][j] = log(T[i][j]);
        }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> M[i][j];
            M[i][j] = log(M[i][j]);
        }
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