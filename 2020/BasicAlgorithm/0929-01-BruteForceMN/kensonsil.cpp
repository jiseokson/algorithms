#include <iostream>
using namespace std;

int n, k;
int kit[10];
bool used[10];

int nokensonsil(int weight, int index)
{
    if (index == n)
        return 1;

    int res = 0;

    for (int i = 0; i < n; i++) {
        if (used[i] == true)
            continue;

        if (weight + kit[i] - k >= 500) {
            used[i] = true;
            res += nokensonsil(weight + kit[i] - k, index + 1);
            used[i] = false;
        }
    }

    return res;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> kit[i];
    cout << nokensonsil(500, 0);
    return 0;
}