#include <iostream>
#include <queue>
using namespace std;

inline bool in_range(int w, int h, int row, int col)
{
    if (0 <= row && row < h && 0 <= col && col < w) return true;
    else return false;
}

int main(void)
{
    while (true) {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0) break;

        bool map[50][50];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cin >> map[i][j];
        }

        int island_count = 0;
        queue<int> row_q;
        queue<int> col_q;
        bool visited[50][50] = {false};

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == false || visited[i][j]) continue;

                island_count++;

                row_q.push(i);
                col_q.push(j);
                visited[i][j] = true;

                while (!row_q.empty()) {
                    int cur_row = row_q.front();
                    int cur_col = col_q.front();
                    row_q.pop(), col_q.pop();

                    for (int k = 0; k < 8; k++) {
                        int next_row = cur_row + dx[k];
                        int next_col = cur_col + dy[k];

                        if (in_range(w, h, next_row, next_col) && map[next_row][next_col] && visited[next_row][next_col] == false) {
                            row_q.push(next_row);
                            col_q.push(next_col);
                            visited[next_row][next_col] = true;
                        }
                    }
                }
            }
        }

        cout << island_count << '\n';
    }

    return 0;
}