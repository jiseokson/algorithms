#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ns[10];
int arr[10];

void repeperm(int index) 
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[index] = ns[i];
        repeperm(index + 1);
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n);
    repeperm(0);
    return 0;
}