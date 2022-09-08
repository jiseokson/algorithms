#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using vi = vector<int>;

int n;
vi h;

inline int height(int i) {
    if (i == -1 || i == n) return 0;
    return h[i];
}

int max_box() {
    int res = 0;
    stack<int> s;

    s.push(-1);
    for (int right = 0; right <= n; ++right) {
        if (height(s.top()) < height(right))
            s.push(right);
        else {
            while (s.size() > 1 && height(s.top()) > height(right)) {
                int mid = s.top(); s.pop();
                int left = s.top();
                res = max(res, height(mid) * (right - left - 1));
            }
            s.push(right);
        }
    }

    return res;
}

int main(void) {
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        h = vi(n);
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        cout << max_box() << '\n';
    }

    return 0;
}