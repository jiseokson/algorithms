#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

inline bool in_range(int n, int m, int row, int col)
{
    if (0 <= row && row < n && 0 <= col && col < m) return true;
    else return false;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    bool map[100][100] = {false};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    }

    queue<int> row_q;
    queue<int> col_q;
    int move_count[100][100] = {0};
    bool visited[100][100] = {false};

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    row_q.push(0);
    col_q.push(0);
    visited[0][0] = true;
    move_count[0][0] = 1;

    while (!row_q.empty()) {
        int cur_row = row_q.front();
        int cur_col = col_q.front();
        row_q.pop(), col_q.pop();

        if (cur_row == n - 1 && cur_col == m - 1) break;

        for (int dir = 0; dir < 4; dir++) {
            int next_row = cur_row + dx[dir];
            int next_col = cur_col + dy[dir];

            if (in_range(n, m, next_row, next_col) && map[next_row][next_col] && visited[next_row][next_col] == false) {
                row_q.push(next_row);
                col_q.push(next_col);
                visited[next_row][next_col] = true;
                move_count[next_row][next_col] = move_count[cur_row][cur_col] + 1;
            }
        }
    }

    cout << move_count[n - 1][m - 1];

    return 0;
}