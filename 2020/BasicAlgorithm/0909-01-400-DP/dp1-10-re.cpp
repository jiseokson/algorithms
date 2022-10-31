#include <iostream>
using namespace std;

int memo[1001];

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
        int maxj = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (al[j] < al[i] && maxj < memo[j] + 1)
                maxj = memo[j] + 1;
        }
        memo[i] = maxj;
        if (ans < memo[i])
            ans = memo[i];
    }

    cout << ans;

    delete []al;
    return 0;
}