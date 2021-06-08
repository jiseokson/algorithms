#include <iostream>

using namespace std;

typedef long long ll;

void dragon(string seed, int gen, int p) {
    if (gen == 0) {
        cout << seed[p - 1];
        return ;
    }

    for (char c : seed) {
        if (c == 'X') {
            int temp = (3 * ((ll)1 << gen) - 2);
            if (temp < p) p -= temp;
            else dragon("X+YF", gen - 1, p);
        } else if (c == 'Y') {
            int temp = ((3 * ((ll)1 << gen - 1) - 2));
            if (temp < p) p -= temp;
            else dragon("FX-Y", gen - 1, p);
        } else if (p > 1) --p;
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

    int c, n, p, l;
    cin >> c;

    while (c--) {
        cin >> n >> p >> l;
        for (int i = 0; i < l; ++i)
            dragon("FX", n, p + i);
        cout << '\n';
    }

    return 0;
}