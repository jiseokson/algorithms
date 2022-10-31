#include <iostream>
using namespace std;

int memo[1001] = {0};

int maxcomb(int pl[], int len, int n)
{
    if (n == 0)
        return 0;

    if (memo[n] != 0)
        return memo[n];

    int max = 0;
    for (int i = 1; i <= len && n - i >= 0; i++) {
        int temp = pl[i] + maxcomb(pl, len, n - i);
        if (max < temp) {
            max = temp;
        }
    }

    memo[n] = max;
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

    cout << maxcomb(pl, n, n);
    delete []pl;
    return 0;
}