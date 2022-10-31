#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <queue>
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

    queue<pair<int, int>> q;
    bool visited[30][30] = {false};
    vector<int> danji_num;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 || visited[i][j]) continue;

            int node_count = 0;
            q.push(make_pair(i, j));
            visited[i][j] = true;

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                node_count++;

                int cur_row = cur.first;
                int cur_col = cur.second;

                if (arr[cur_row + 1][cur_col] && visited[cur_row + 1][cur_col] == false) {
                    q.push(make_pair(cur_row + 1, cur_col));
                    visited[cur_row + 1][cur_col] = true;
                }
                if (arr[cur_row][cur_col + 1] && visited[cur_row][cur_col + 1] == false) {
                    q.push(make_pair(cur_row, cur_col + 1));
                    visited[cur_row][cur_col + 1] = true;
                }
                if (0 <= cur_row - 1 && arr[cur_row - 1][cur_col] && visited[cur_row - 1][cur_col] == false) {
                    q.push(make_pair(cur_row - 1, cur_col));
                    visited[cur_row - 1][cur_col] = true;
                }
                if (0 <= cur_col - 1 && arr[cur_row][cur_col - 1] && visited[cur_row][cur_col - 1] == false) {
                    q.push(make_pair(cur_row, cur_col - 1));
                    visited[cur_row][cur_col - 1] = true;
                }
            }

            danji_num.push_back(node_count);
        }
    }

    sort(danji_num.begin(), danji_num.end());
    cout << danji_num.size() << '\n';
    for (int i : danji_num)
        cout << i << '\n';

    return 0;
}