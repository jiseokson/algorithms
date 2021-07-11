#include <iostream>
#include <vector>

#define MAX_LEN 1000000000
#define INIT_SEED 0
#define EXPANDED_X 1
#define EXPANDED_Y 2

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vvll dp;

int dragon_len(int seed, int gen) {
    if (gen == 0) return seed == INIT_SEED ? 2 : 4;
    ll &ret = dp[seed][gen];
    if (ret != -1) return ret;
    if (seed == INIT_SEED) ret = 1 + dragon_len(EXPANDED_X, gen - 1);
    else ret = dragon_len(EXPANDED_X, gen - 1) + dragon_len(EXPANDED_Y, gen - 1) + 2;
    return ret = min<ll>(ret, MAX_LEN);
}

void dragon(string seed, int gen, int p) {
    if (gen == 0) {
        cout << seed[p - 1];
        return ;
    }

    for (char c: seed) {
        if (c == 'X') {
            int temp = dragon_len(EXPANDED_X, gen - 1);
            if (temp < p)
                p -= temp;
            else {
                dragon("X+YF", gen - 1, p);
                return ;
            }
        } else if (c == 'Y') {
            int temp = dragon_len(EXPANDED_Y, gen - 1);
            if (temp < p)
                p -= temp;
            else {
                dragon("FX-Y", gen - 1, p);
                return ;
            }
        } else if (p > 1)
            --p;
        else {
            cout << c;
            return ;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n, p, l;
        cin >> n >> p >> l;

        dp = vvll(3, vll(n + 1, -1));

        for (int i = 0; i < l; ++i)
            dragon("FX", n, p + i);
        cout << '\n';
    }
    
    return 0;
}