#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pi;

inline bool in_range(int n, int row, int col)
{
    if (0 <= row && row < n && 0 <= col && col < n) return true;
    return false;
}

int main(void)
{
    int n;
    bool map[100][100] = {false};

    queue<pi> q1;
    int id[100][100] = {0};
    bool check[100][100] = {false};

    queue<pi> q2;
    int dist[100][100] = {0};

    int drow[] = {0, 0, -1, 1};
    int dcol[] = {-1, 1, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == false) dist[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) { // assign island id
        for (int j = 0; j < n; j++) {
            if (check[i][j] || map[i][j] == false) continue;

            int island_id = n * i + j;
            q1.push(make_pair(i, j));
            check[i][j] = true;

            while (!q1.empty()) {
                pi cur = q1.front();
                q1.pop();

                id[cur.first][cur.second] = island_id;
                q2.push(cur);

                for (int dir = 0; dir < 4; dir++) {
                    int next_row = cur.first + drow[dir];
                    int next_col = cur.second + dcol[dir];

                    if (in_range(n, next_row, next_col) == false || map[next_row][next_col] == false || check[next_row][next_col]) continue;

                    q1.push(make_pair(next_row, next_col));
                    check[next_row][next_col] = true;
                }
            }
        }
    }

    int ans = 100 * 100;

    while (!q2.empty()) {
        pi cur = q2.front();
        q2.pop();

        for (int dir = 0; dir < 4; dir++) {
            int next_row = cur.first + drow[dir];
            int next_col = cur.second + dcol[dir];

            if (in_range(n, next_row, next_col) == false || map[next_row][next_col]) continue;

            if (dist[next_row][next_col] >= 0 && id[cur.first][cur.second] != id[next_row][next_col]) {
                if (dist[cur.first][cur.second] != dist[next_row][next_col]) ans = min(ans, 2 * dist[cur.first][cur.second] + 1);
                else ans = min(ans, 2 * dist[cur.first][cur.second]);
            } else if (dist[next_row][next_col] == -1) {
                q2.push(make_pair(next_row, next_col));
                dist[next_row][next_col] = dist[cur.first][cur.second] + 1;
                id[next_row][next_col] = id[cur.first][cur.second];
            }
        }
    }

    cout << ans;

    return 0;
}