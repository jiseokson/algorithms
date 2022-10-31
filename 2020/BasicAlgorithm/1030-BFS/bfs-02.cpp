#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    queue<int> move_q;
    bool check[100001] = {false};
    int from[100001] = {0};

    q.push(n);
    move_q.push(0);
    check[n] = true;

    while (!q.empty()) {
        int cur = q.front();
        int cur_move = move_q.front();
        q.pop(), move_q.pop();

        if (cur == k) {
            cout << cur_move << '\n';
            break;
        }

        for (int next : {cur - 1, cur + 1, 2 * cur}) {
            if (0 <= next && next <= 100000 && check[next] == false) {
                q.push(next);
                move_q.push(cur_move + 1);
                check[next] = true;
                from[next] = cur;
            }
        }
    }

    stack<int> nodes;
    while (k != n) {
        nodes.push(k);
        k = from[k];
    }
    nodes.push(n);

    while (!nodes.empty()) {
        cout << nodes.top() << ' ';
        nodes.pop();
    }

    return 0;
}