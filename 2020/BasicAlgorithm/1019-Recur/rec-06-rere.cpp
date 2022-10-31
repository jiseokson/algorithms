#include <iostream>
#include <algorithm>
using namespace std;

int k;
char signs[10];
int arr[10];

long long maxNum = 0;
long long minNum = 9876543210;

inline bool check(char sign, int a, int b)
{
    if (sign == '<') return a < b;
    else return a > b;
}

void makeAns(int index, int select)
{
    if (index > k) {
        do {
            bool ok = true;
            long long num = 0;
            for (int i = 0; i < k; i++) {
                if (!check(signs[i], arr[i], arr[i + 1])) {
                    ok = false;
                    break;
                }
                num = num * 10 + arr[i];
            }
            if (ok) {
                num = num * 10 + arr[k];
                maxNum = max(maxNum, num);
                minNum = min(minNum, num);
            }
        } while (next_permutation(arr, arr + k + 1));
    }
    if (select > 9)
        return;

    arr[index] = select;
    makeAns(index + 1, select + 1);
    makeAns(index, select + 1);
}

int main(void)
{
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> signs[i];

    makeAns(0, 0);

    int exp = 1;
    for (int i = 0; i < k; i++) exp *= 10;
    for (int j = exp; j > 0; j /= 10) cout << maxNum / j % 10;
    cout << '\n';
    for (int j = exp; j > 0; j /= 10) cout << minNum / j % 10;

    return 0;
}