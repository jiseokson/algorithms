#include <iostream>
#include <queue>
using namespace std;

inline bool in_range(int l, int row, int col)
{
    if (0 <= row && row < l && 0 <= col && col < l) return true;
    else return false;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--) {
        int l;
        int cur_row, cur_col;
        int dest_row, dest_col;
        cin >> l;
        cin >> cur_row >> cur_col;
        cin >> dest_row >> dest_col;

        int min_move_count = 300 * 300;
        queue<int> move_count_q;
        queue<int> row_q;
        queue<int> col_q;
        bool visited[300][300] = {false};

        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        move_count_q.push(0);
        row_q.push(cur_row);
        col_q.push(cur_col);
        visited[cur_row][cur_col] = true;

        while (!move_count_q.empty()) {
            int cur_move_count = move_count_q.front();
            cur_row = row_q.front();
            cur_col = col_q.front();
            move_count_q.pop(), row_q.pop(), col_q.pop();

            if (cur_row == dest_row && cur_col == dest_col)
                min_move_count = min(min_move_count, cur_move_count);

            for (int dir = 0; dir < 8; dir++) {
                int next_row = cur_row + dx[dir];
                int next_col = cur_col + dy[dir];

                if (in_range(l, next_row, next_col) && visited[next_row][next_col] == false) {
                    move_count_q.push(cur_move_count + 1);
                    row_q.push(next_row);
                    col_q.push(next_col);
                    visited[next_row][next_col] = true;
                }
            }
        }

        cout << min_move_count << '\n';
    }

    return 0;
}