#include <iostream>
using namespace std;

struct Tet {
    int size_r, size_c;
    int tet_row[4], tet_col[4];
};

Tet tet1 = {
    1, 4,
    {0, 0, 0, 0},
    {0, 1, 2, 3}
};

Tet tet2 = {
    1, 4,
    {0, 1, 2, 3},
    {0, 0, 0, 0},
};

Tet tet3 = {
    2, 2,
    {0, 0, 1, 1},
    {0, 1, 0, 1}
};

Tet tet4 = {
    3, 2,
    {0, 1, 2, 2},
    {0, 0, 0, 1}
};

Tet tet5 = {
    2, 2,
    {0, 1, 2, 0},
    {0, 0, 0, 1}
};

int main(void)
{
    int arr[500][500] = {0};
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    return 0;
}