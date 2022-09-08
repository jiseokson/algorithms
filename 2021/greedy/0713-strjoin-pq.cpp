#include <iostream>
#include <queue>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq;
        FOR(i, n) {
            int a;
            cin >> a;
            pq.push(a);
        }

        int ans = 0;
        while (pq.size() > 1) {
            int temp = pq.top(); pq.pop();
            temp += pq.top(); pq.pop();
            pq.push(temp);
            ans += temp;
        }

        cout << ans << '\n';
    }

    return 0;
}