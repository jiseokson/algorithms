#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int al[n];
    int d[n] = {1};

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        al[i] = a;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (al[j] < al[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
        if (ans < d[i])
            ans = d[i];
    }

    cout << ans;
    return 0;
}