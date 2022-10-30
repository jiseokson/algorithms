#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int N, W;
vs stuff;
vi w, p;
vvi cache, choice;

int pack(int i, int v)
{
    if (i == N) return 0;
    int &ret = cache[i][v];
    if (ret != -1) return ret;
    ret = pack(i + 1, v);
    choice[i][v] = v;
    int temp = p[i] + pack(i + 1, v - w[i]);
    if (v - w[i] >= 0 && ret < temp) {
        ret = temp;
        choice[i][v] = v - w[i];
    }
    return ret;
}

int reconstruct(vs &packs, int i, int v)
{
    if (i == N) return 0;
    int ret = 0;
    if (v != choice[i][v]) {
        packs.push_back(stuff[i]);
        ++ret;
    }
    return ret += reconstruct(packs, i + 1, choice[i][v]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> N >> W;
        stuff = vs(N);
        w = vi(N);
        p = vi(N);
        cache = vvi(N + 1, vi(W + 1, -1));
        choice = vvi(N + 1, vi(W + 1, -1));
        for (int i = 0; i < N; ++i)
            cin >> stuff[i] >> w[i] >> p[i];
        vs packs;
        int max_p = pack(0, W);
        int cnt = reconstruct(packs, 0, W);
        cout << max_p << " " << cnt << "\n";
        for (int i = 0; i < packs.size(); ++i)
            cout << packs[i] << "\n";
    }
    return 0;
}