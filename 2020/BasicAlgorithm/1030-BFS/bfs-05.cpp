#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

struct node {
    int row, col;
    int wall_break;
};

inline bool in_range(int m, int n, int row, int col)
{
    if (0 <= row && row < m && 0 <= col && col < n) return true;
    else return false;
}

int main(void)
{
    int n, m;

    bool map[100][100] = {false};
    bool check[100][100] = {false};

    int drow[] = {0, 0, -1, 1};
    int dcol[] = {-1, 1, 0, 0};

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);
    }

    deque<node> dq;
    dq.push_back((node){0, 0, 0});
    check[0][0] = true;

    while (!dq.empty()) {
        node cur = dq.front();
        dq.pop_front();

        if (cur.row == m - 1 && cur.col == n - 1) {
            cout << cur.wall_break;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int next_row = cur.row + drow[dir];
            int next_col = cur.col + dcol[dir];

            if (in_range(m, n, next_row, next_col) && check[next_row][next_col] == false) {
                if (map[next_row][next_col] == 1) {
                    dq.push_back((node){next_row, next_col, cur.wall_break + 1});
                    check[next_row][next_col] = true;
                } else {
                    dq.push_front((node){next_row, next_col, cur.wall_break});
                    check[next_row][next_col] = true;
                }
            }
        }
    }
}