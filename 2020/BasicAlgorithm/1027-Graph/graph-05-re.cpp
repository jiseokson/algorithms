#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    bool arr[30][30] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%1d", &arr[i][j]);
    }

    vector<int> danji_nums;
    queue<int> row_q;
    queue<int> col_q;
    bool visited[30][30] = {false};

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0;  j < n; j++) {
            if (arr[i][j] == 0 || visited[i][j])  continue;

            int danji_size = 0;
            row_q.push(i);
            col_q.push(j);
            visited[i][j] = true;

            while (!row_q.empty()) {
                int cur_row = row_q.front();
                int cur_col = col_q.front();
                row_q.pop(), col_q.pop();

                danji_size++;

                for (int k = 0; k < 4; k++) {
                    int next_row = cur_row + dx[k];
                    int next_col = cur_col + dy[k];

                    if (0 <= next_row && next_row < n && 0 <= next_col && next_col < n
                    && arr[next_row][next_col] && visited[next_row][next_col] == false) {
                        row_q.push(next_row);
                        col_q.push(next_col);
                        visited[next_row][next_col] = true;
                    }
                }
            }

            danji_nums.push_back(danji_size);
        }
    }

    sort(danji_nums.begin(), danji_nums.end());
    cout << danji_nums.size() << '\n';
    for (int dn : danji_nums)
        cout << dn << '\n';
    
    return 0;
}