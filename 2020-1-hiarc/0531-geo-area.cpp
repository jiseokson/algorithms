#include <iostream>

using namespace std;

typedef long long ll;
typedef long double lld;

struct vec {
    ll x, y;
};

int n;
vec v[10000];

inline ll ccw(vec &o, vec &u, vec &v) {
    return (u.x - o.x) * (v.y - o.y) - (u.y - o.y) * (v.x - o.x);
}

int main(void) {
    cout << fixed;
    cout.precision(1);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i].x >> v[i].y;

    lld area = 0.0;
    for (int i = 1; i <= n - 2; ++i)
        area += ccw(v[0], v[i], v[i + 1]);
    area = abs(area) / 2.0;

    cout << area;

    return 0;
}