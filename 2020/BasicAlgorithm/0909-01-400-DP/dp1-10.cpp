#include <iostream>
using namespace std;

int memo[1001] = {0};

int lis(int al[], int n, int i)
{
    if (memo[i] != 0)
        return memo[i];
    if (i + 1 == n)
        return 1;

    int res = 1;
    for (int j = i + 1; j < n; j++) {
        if (al[i] < al[j]) {
            int nres = 1 + lis(al, n, j);
            if (res < nres)
                res = nres;
        }
    }

    memo[i] = res;
    return memo[i];
}

int main(void)
{
    int n;
    cin >> n;

    int * al = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        al[i] = a;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int nans = lis(al, n, i);
        if (ans < nans)
            ans = nans;
    }
    cout << ans;

    delete []al;
    return 0;
}