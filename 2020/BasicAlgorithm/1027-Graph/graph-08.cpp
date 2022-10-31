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

inline void init_check(int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            check[i][j] = false;
    }
}

int main(void)
{
    int m, n;
    int do_count = 0;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) do_count++;
        }
    }

    int min_days_count = 1000 * 1000;
    int check_count = 0;
    queue<int> row_q;
    queue<int> col_q;

    int drow[] = {0, 0, -1, 1};
    int dcol[] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 1) continue;

            init_check(n, m);
            int days_count = 0;
            row_q.push(i);
            col_q.push(j);
            check[i][j] = true;

            while (!row_q.empty()) {
                int cur_row = row_q.front();
                int cur_col = col_q.front();
                row_q.pop(), col_q.pop();

                days_count = max(days_count, map[cur_row][cur_col]);
                // days_count = map[cur_row][cur_col];

                for (int dir = 0; dir < 4; dir++) {
                    int next_row = cur_row + drow[dir];
                    int next_col = cur_col + dcol[dir];

                    if (in_range(n, m, next_row, next_col) && map[next_row][next_col] != -1 && map[next_row][next_col] != 1) {
                        if (check[next_row][next_col] == false) {
                            row_q.push(next_row);
                            col_q.push(next_col);
                            check[next_row][next_col] = true;
                            if (map[next_row][next_col] > 1)
                                map[next_row][next_col] = min(map[next_row][next_col], map[cur_row][cur_col] + 1);
                            else {
                                check_count++;
                                map[next_row][next_col] = map[cur_row][cur_col] + 1;
                            }
                        }

                    }
                }
                
            }

            min_days_count = min(min_days_count, days_count);
        }
    }
    
    if (check_count == do_count) cout << min_days_count - 1;
    else cout << -1;

    cout << '\n'; // deb
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == -1) cout << ' ' << ' ' ;
            else cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}