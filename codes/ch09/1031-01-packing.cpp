#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

const int neg_inf = -987654321;

int N, W;
vs stuff;
vi w, p;
vvi cache;

int pack(int i, int v)
{
    if (v < 0) return neg_inf;
    if (i == N) return 0;
    int &ret = cache[i][v];
    if (ret != -1) return ret;
    return ret = max(pack(i + 1, v), p[i] + pack(i + 1, v - w[i]));
}

void reconstruct(vs &packs, int i, int v)
{
    if (i == N) return;
    if (pack(i, v) == pack(i + 1, v)) {
        reconstruct(packs, i + 1, v);
    } else {
        packs.push_back(stuff[i]);
        reconstruct(packs, i + 1, v - w[i]);
    }
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
        for (int i = 0; i < N; ++i)
            cin >> stuff[i] >> w[i] >> p[i];
        vs packs;
        reconstruct(packs, 0, W);
        cout << pack(0, W) << " " << packs.size() << "\n";
        for (int i = 0; i < packs.size(); ++i)
            cout << packs[i] << "\n";
    }

    return 0;
}