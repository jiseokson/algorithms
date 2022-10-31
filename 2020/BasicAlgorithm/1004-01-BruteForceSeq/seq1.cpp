#include <iostream>
#include <algorithm>
using namespace std;

int n;
int il[100001];

void ans()
{
    for (int i = n - 2; i >= 0; i--) {
        if (il[i] != *max_element(il + i, il + n)) {
            for (int j = 0; j < i; j++)
                cout << il[j] << ' ';

            int target = il[i];
            int avoid;
            sort(il + i, il + n);
            for (int j = i; j < n; j++) {
                if (il[j] == target) {
                    avoid = il[j + 1];
                    cout << il[j + 1] << ' ';
                    break;
                }
            }
            for (int j = i; j < n; j++) {
                if (il[j] == avoid)
                    continue;
                cout << il[j] << ' ';
            }
            return;
        }
    }

    cout << "-1";
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> il[i];
    ans();
    return 0;
}