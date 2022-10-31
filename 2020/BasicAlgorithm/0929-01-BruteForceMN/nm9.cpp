#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ns[10];
int arr[10];
int used[10];

void perm(int index)
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == true)
            continue;
        used[i] = true;
        arr[index] = ns[i];
        perm(index + 1);
        used[i] = false;
        while (ns[i] == ns[i + 1]) i++;
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n);
    perm(0);
    return 0;
}