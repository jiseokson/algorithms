#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int al[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        al[i] = a;
    }

    int memo[n] = {al[0]};
    int ans = al[0];
    for (int i = 1; i < n; i++) {
        if (al[i] < al[i] + memo[i - 1]) {
            memo[i] = al[i] + memo[i - 1];
        } else {
            memo[i] = al[i];
        }

        if (ans < memo[i])
            ans = memo[i];
    }

    cout << ans;
    return 0;
}