#include <iostream>
#include <queue>
using namespace std;

typedef struct _Node {
    int emoji, clip;
    int op_count;
} Node;

int main(void)
{
    int s;
    cin >> s;

    queue<Node> q;
    bool check[1001][1001] = {false};

    q.push((Node){1, 1, 1});
    check[1][1] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.emoji == s) {
            cout << cur.op_count;
            return 0;
        }

        if (cur.emoji + cur.clip <= s && check[cur.emoji + cur.clip][cur.clip] == false) {
            q.push((Node){cur.emoji + cur.clip, cur.clip, cur.op_count + 1});
            check[cur.emoji + cur.clip][cur.clip] = true;
        }

        if (cur.emoji > cur.clip && check[cur.emoji][cur.emoji] == false) {
            q.push((Node){cur.emoji, cur.emoji, cur.op_count + 1});
            check[cur.emoji][cur.emoji] = true;
        }

        if (0 < cur.emoji - 1 && check[cur.emoji - 1][cur.clip] == false) {
            q.push((Node){cur.emoji - 1, cur.clip, cur.op_count + 1});
            check[cur.emoji - 1][cur.clip] = true;
        }
    }
}