#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
bool check[1000][1000];

inline bool in_range(int n, int m, int row, int col)
{
    if (0 <= row && row < n && 0 <= col && col < m) return true;
    else return false;
}

int main(void)
{
    queue<int> row_q;
    queue<int> col_q;
    int blank_count = 0;
    int check_count = 0;

    int drow[] = {0, 0, -1, 1};
    int dcol[] = {-1, 1, 0, 0};

    int days_count = 0;

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                blank_count++;
            } else if (map[i][j] == 1) {
                row_q.push(i);
                col_q.push(j);
                check[i][j] = true;
            }
        }
    }

    while (!row_q.empty()) {
        int cur_row = row_q.front();
        int cur_col = col_q.front();
        row_q.pop(), col_q.pop();

        days_count = map[cur_row][cur_col];

        for (int dir = 0; dir < 4; dir++) {
            int next_row = cur_row + drow[dir];
            int next_col = cur_col + dcol[dir];

            if (in_range(n, m, next_row, next_col) && map[next_row][next_col] != -1 && map[next_row][next_col] != 1 && check[next_row][next_col] == false) {
                row_q.push(next_row);
                col_q.push(next_col);
                check[next_row][next_col] = true;
                check_count++;
                map[next_row][next_col] = map[cur_row][cur_col] + 1;
            }
        }
    }

    if (check_count == blank_count) cout << days_count - 1;
    else cout << -1;

    return 0;
}