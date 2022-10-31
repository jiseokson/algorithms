#include <iostream>
using namespace std;

int d[10001];

int maxSelect(int quantity[], int i)
{
    if (i < 0)
        return 0;
    if (i == 0)
        return quantity[0];
    if (d[i] != 0)
        return d[i];

    d[i] = max( max(maxSelect(quantity, i - 2), maxSelect(quantity, i - 3)) + quantity[i],
                max(maxSelect(quantity, i - 3), maxSelect(quantity, i - 4)) + quantity[i] + quantity[i - 1]);
    return d[i];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int quantity[n];
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        quantity[i] = q;
    }

    if (n == 1)
        cout << quantity[0];
    else if (n == 2)
        cout << quantity[0] + quantity[1];
    else
        cout << max( maxSelect(quantity, n - 1), maxSelect(quantity, n - 2) );

    return 0;
}