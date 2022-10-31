#include <iostream>
using namespace std;

int k;
char signs[15] = {'>'};

int arr[15] = {10};
bool used[15] = {false};
 
long long maxNum = 0;
long long minNum = 9876543210;

void makeAns(int index)
{
    if (index > k + 1) {
        long long num = 0;
        for (int i = 1; i <= k + 1; i++)
            num = num * 10 + arr[i];
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
        return;
    }

    if (signs[index - 1] == '<') {
        for (int i = arr[index - 1] + 1; i <= 9; i++) {
            if (used[i]) continue;
            used[i] = true;
            arr[index] = i;
            makeAns(index + 1);
            used[i] = false;
        }
    } else {
        for (int i = arr[index - 1] - 1; i >= 0; i--) {
            if (used[i]) continue;
            used[i] = true;
            arr[index] = i;
            makeAns(index + 1);
            used[i] = false;
        }
    }
}

int main(void)
{
    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> signs[i];

    makeAns(1);

    int exp = 1;
    for (int i = 0; i < k; i++) exp *= 10;
    for (int j = exp; j > 0; j /= 10) cout << maxNum / j % 10;
    cout << '\n';
    for (int j = exp; j > 0; j /= 10) cout << minNum / j % 10;

    return 0;
}