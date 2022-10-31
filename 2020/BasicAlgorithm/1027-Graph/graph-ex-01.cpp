#include <iostream>
#include <queue>
using namespace std;

inline bool in_range(int m, int n, int row, int col)
{
    if (0 <= row && row < m && 0 <= col && col < n) return true;
    else return false;
}

int main(void)
{
    char map[50][50] = {0};

    queue<int> row_q;
    queue<int> col_q;
    queue<int> latest_dir_q;
    bool check[50][50] = {false};

    int drow[] = {0, -1, 1, 0};
    int dcol[] = {-1, 0, 0, 1};

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
            map[i][j] = row[j];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j]) continue;

            char color = map[i][j];
            row_q.push(i);
            col_q.push(j);
            latest_dir_q.push(-1);
            check[i][j] = true;

            while (!latest_dir_q.empty()) {
                int cur_row = row_q.front();
                int cur_col = col_q.front();
                int latest_dir = latest_dir_q.front();
                row_q.pop(), col_q.pop(), latest_dir_q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    if (dir == 3 - latest_dir) continue;

                    int next_row = cur_row + drow[dir];
                    int next_col = cur_col + dcol[dir];

                    if (in_range(m, n, next_row, next_col) && map[next_row][next_col] == color) {
                        if (check[next_row][next_col] == false) {
                            row_q.push(next_row);
                            col_q.push(next_col);
                            latest_dir_q.push(dir);
                            check[next_row][next_col] = true;
                        } else {
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "No";
    return 0;
}