#include <iostream>
#include <deque>
using namespace std;

struct Node {
    int pos, time;
};

int main(void)
{
    int n, k;
    cin >> n >> k;

    deque<Node> dq;
    bool check[100001] = {false};

    dq.push_back((Node){n, 0});
    check[n] = true;

    if (n > k) {
        cout << n - k;
        return 0;
    }

    while(!dq.empty()) {
        Node cur = dq.front();
        dq.pop_front();

        if (cur.pos == k) {
            cout << cur.time;
            return 0;
        }

        if (cur.pos * 2 <= 100000 && check[2 * cur.pos] == false) {
            dq.push_front((Node){cur.pos * 2, cur.time});
            check[cur.pos * 2] = true;
        }
        if (cur.pos + 1 < 100000 && check[cur.pos + 1] == false) {
            dq.push_back((Node){cur.pos + 1, cur.time + 1});
            check[cur.pos + 1] = true;
        }
        if (0 <= cur.pos - 1 && check[cur.pos - 1] == false) {
            dq.push_back((Node){cur.pos - 1, cur.time + 1});
            check[cur.pos - 1] = false;
        }
    }
}