#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int adj_mat[10][10];
bool visited_dfs_adj_mat[10] = {false};

vector<int> adj_list[10];
bool visited_dfs_adj_list[10] = {false};

void dfs_adj_mat(int cur)
{
    visited_dfs_adj_mat[cur] = true;
    cout << cur << '\n';

    for (int i = 1; i <= 6; i++) {
        if (adj_mat[cur][i] && visited_dfs_adj_mat[i] == false)
            dfs_adj_mat(i);
    }
}

void dfs_adj_list(int cur)
{
    visited_dfs_adj_list[cur] = true;
    cout << cur << '\n';

    for (int i : adj_list[cur]) {
        if (visited_dfs_adj_list[i] == false)
            dfs_adj_list(i);
    }
}

int main(void)
{
    adj_mat[1][2] = adj_mat[2][1] = true;
    adj_mat[2][3] = adj_mat[3][2] = true;
    adj_mat[3][4] = adj_mat[4][3] = true;
    adj_mat[4][5] = adj_mat[5][4] = true;
    adj_mat[1][5] = adj_mat[5][1] = true;
    adj_mat[2][5] = adj_mat[5][2] = true;
    adj_mat[4][6] = adj_mat[6][4] = true;

    cout << "DFS search - adjacent matrix ver\n";
    dfs_adj_mat(1);
    cout << '\n';





    adj_list[1].push_back(2);
    adj_list[1].push_back(5);
    adj_list[2].push_back(1);
    adj_list[2].push_back(3);
    adj_list[2].push_back(5);
    adj_list[3].push_back(2);
    adj_list[3].push_back(4);
    adj_list[4].push_back(3);
    adj_list[4].push_back(5);
    adj_list[4].push_back(6);
    adj_list[5].push_back(1);
    adj_list[5].push_back(2);
    adj_list[5].push_back(4);
    adj_list[6].push_back(4);

    cout << "DFS search - adjacent list ver\n";
    dfs_adj_list(1);
    cout << '\n';





    queue<int> q;
    bool visited_bfs_adj_mat[10] = {false};

    cout << "BFS search - adjacent matrix ver\n";

    visited_bfs_adj_mat[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << '\n';

        for (int i = 1; i <= 6; i++) {
            if (adj_mat[cur][i] && visited_bfs_adj_mat[i] == false) {
                visited_bfs_adj_mat[i] = true;
                q.push(i);
            }
        }
    }
    cout << '\n';




    
    bool visited_bfs_adj_list[10] = {false};

    cout << "BFS search - adjacent list ver\n";

    visited_bfs_adj_list[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << '\n';

        for (int i : adj_list[cur]) {
            if (visited_bfs_adj_list[i] == false) {
                visited_bfs_adj_list[i] = true;
                q.push(i);
            }
        }
    }


    return 0;
}