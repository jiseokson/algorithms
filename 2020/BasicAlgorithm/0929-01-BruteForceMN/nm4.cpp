#include <iostream>
using namespace std;

int n, m;
int arr[10];
int latest = 1;

void repecomb(int index)
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = latest; i <= n; i++) {
        arr[index] = i;
        latest = i;
        repecomb(index + 1);
    }
}

int main(void)
{
    cin >> n >> m;
    repecomb(0);
    return 0;
}