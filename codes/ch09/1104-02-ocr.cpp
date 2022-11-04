#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using vs = vector<string>;
using msi = map<string, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vvd = vector<vd>;

int wc, tc;
vs w;
msi wi;
vvd T, M;

int n;
vi clf;
vvd cache;
vvi choice;

double max_prob(int prev_wi, int i)
{
    if (i == n) return 1.0;
    double& ret = cache[prev_wi][i];
    if (ret != -1) return ret;

    for (int cur_wi = 1; cur_wi <= wc; ++cur_wi) {
        double temp = T[prev_wi][cur_wi] * M[cur_wi][clf[i]] * max_prob(cur_wi, i + 1);
        if (ret < temp) {
            choice[prev_wi][i] = cur_wi;
            ret = temp;
        }
    }
    return ret;
}

void reconst(int prev_wi, int i)
{
    if (i == n) {
        cout << "\n";
        return;
    }
    cout << w[choice[prev_wi][i]] << ' ';
    reconst(choice[prev_wi][i], i + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> wc >> tc;
    w = vs(wc + 1);
    T = vvd(wc + 1, vd(wc + 1));
    M = vvd(wc + 1, vd(wc + 1));
    for (int i = 1; i <= wc; ++i) {
        cin >> w[i];
        wi[w[i]] = i;
    }
    for (int i = 1; i <= wc; ++i)
        cin >> T[0][i];
    for (int i = 1; i <= wc; ++i) {
        for (int j = 1; j <= wc; ++j) {
            cin >> T[i][j];
        }
    }
    for (int i = 1; i <= wc; ++i) {
        for (int j = 1; j <= wc; ++j) {
            cin >> M[i][j];
        }
    }

    while (tc--) {
        cin >> n;
        clf = vi(n);
        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;
            clf[i] = wi[word];
        }
        cache = vvd(wc + 1, vd(n + 1, -1.0));
        choice = vvi(wc + 1, vi(n + 1, -1));
        max_prob(0, 0);
        reconst(0, 0);
    }

    return 0;
}