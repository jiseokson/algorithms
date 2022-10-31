#include <iostream>
using namespace std;

int arr[10];
bool used[10];

void perm(int index, int n, int m)
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == true)
            continue;
        used[i] = true;
        arr[index] = i;
        perm(index + 1, n, m);
        used[i] = false;
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    perm(0, n, m);
    return 0;
}