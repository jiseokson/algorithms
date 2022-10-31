#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        array[i] = a;
    }

    int d[n] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int maxDj = 0;
        for (int j = 0; j < i; j++) {
            if (array[j] > array[i] && maxDj < d[j])
                maxDj = d[j];
        }
        d[i] = 1 + maxDj;

        if (ans < d[i])
            ans = d[i];
    }

    cout << ans;
    return 0;
}