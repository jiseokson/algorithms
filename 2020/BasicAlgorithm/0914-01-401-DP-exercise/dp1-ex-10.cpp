#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        array[i] = a;
    }

    int dl[n] = {0};
    int dr[n] = {0};

    for (int i = 0; i < n; i++) {
        int maxDl = 0;
        for (int j = 0; j < i; j++) {
            if (array[j] < array[i] && maxDl < dl[j])
                maxDl = dl[j];
        }
        dl[i] = maxDl + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        int maxDr = 0;
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j] && maxDr < dr[j])
                maxDr = dr[j];
        }
        dr[i] = maxDr + 1;
    }

    int ans = 0; // longest bitonic sub seq. len
    for (int i = 0; i < n; i++) {
        if (ans < dl[i] + dr[i] - 1)
            ans = dl[i] + dr[i] - 1;
    }

    cout << ans;
    return 0;
}