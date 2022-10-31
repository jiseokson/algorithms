#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    queue<int> move;
    queue<int> q;
    bool check[100001] = {false};

    move.push(0);
    q.push(n);
    check[n] = true;

    while (!q.empty()) {
        int cur_move = move.front();
        int cur = q.front();
        move.pop(), q.pop();

        if (cur == k) {
            cout << cur_move;
            return 0;
        }

        for (int next : {cur - 1, cur + 1, 2 * cur}) {
            if (0 <= next && next <= 100000 && check[next] == false) {
                move.push(cur_move + 1);
                q.push(next);
                check[next] = true;
            }
        }
    }
}