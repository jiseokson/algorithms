#include <iostream>
using namespace std;

int memo[1001] = {0};

int mincomb(int pl[], int len, int n)
{
    if (n == 0)
        return 0;

    if (memo[n] != 0)
        return memo[n];

    int min = pl[1] + mincomb(pl, len, n - 1);
    for (int i = 2; i <= len && n - i >= 0; i++) {
        int temp = pl[i] + mincomb(pl, len, n - i);
        if (min > temp) {
            min = temp;
        }
    }

    memo[n] = min;
    return memo[n];
}

int main(void)
{
    int n;
    cin >> n;
    int * pl = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        int p;
        cin >>p;
        pl[i] = p; 
    }

    cout << mincomb(pl, n, n);
    delete []pl;
    return 0;
}