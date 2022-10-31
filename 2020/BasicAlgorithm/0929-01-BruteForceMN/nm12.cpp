#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ns[10];
int arr[10];
int latest = 0;

void repecomb(int index)
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = latest; i < n; i++) {
        arr[index] = ns[i];
        latest = i;
        repecomb(index + 1);
        while (ns[i] == ns[i + 1]) i++;
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n);
    repecomb(0);
    return 0;
}