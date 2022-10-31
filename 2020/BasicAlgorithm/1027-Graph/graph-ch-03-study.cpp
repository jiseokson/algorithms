#include <iostream>
#include <queue>
using namespace std;

struct node {
    int row, col;
    int from;
};

int main(void)
{
    int n;
    bool map[100][100] = {false};

    queue<node> q;
    int dist[100][100] = {0}; // dist == -1 : uncheck, dist >= 0 : check

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j]) q.push((node){i, j, -1});
            else dist[i][j] = -1;
        }
    }
}