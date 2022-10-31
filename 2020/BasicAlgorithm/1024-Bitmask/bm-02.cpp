#include <iostream>
using namespace std;

int main(void)
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 0;
    for (int b = 1; b < 1 << n; b++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (b & (1 << i)) sum += arr[i];
        if (sum == s) count++;
    }

    cout << count;

    return 0;
}