#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;
using vi = vector<int>;

struct Fortress {
    int x, y, r;
};

int n;
vector<Fortress> fortress;

inline bool contain(Fortress a, Fortress b) {
    int dSq = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    int deltaRSq = a.r*a.r - 2*a.r*b.r + b.r*b.r;
    return dSq > deltaRSq;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        fortress = vector<Fortress>(n);
        for (int i = 0; i < n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            fortress.push_back({x, y, r});
        }
        sort(fortress.begin(), fortress.end(), contain);

        stack<Fortress> s;
        vi depth;
        s.push(fortress[0]);
        depth.push_back(1);
        for (int i = 1; i < n; ++i) {
            if (contain(s.top(), fortress[i])) {
                s.push(fortress[i]);
                ++depth.back();
            } else {
                while (!contain(s.top(), fortress[i])) {
                    assert(!s.empty());
                    s.pop();
                }
                s.push(fortress[i]);
                depth.push_back(s.size() - 1);
            }
        }
        assert(depth.size() > 0);
        if (depth.size() == 1) cout << depth[0];
        else {
            sort(depth.begin(), depth.end());
            cout << (*depth.rbegin() + *(depth.rbegin() + 1));
        }
        cout << '\n';
    }

    return 0;
}