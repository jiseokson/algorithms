#include <iostream>
#include <algorithm>
using namespace std;

inline bool check(char sign, int a, int b)
{
    if (sign == '<') return a < b;
    else return a > b;
}

inline void print_ans_format(long long ans, int k)
{
    int i = 1;
    for (int j = 0; j < k; j++) i *= 10;
    for (; i > 0; i /= 10)
        cout << ans / i % 10;
    cout << '\n';
}

int main(void)
{
    int k;
    cin >> k;

    char signs[k];
    for (int i = 0; i < k; i++)
        cin >> signs[i];

    int select[10] = {false};
    for (int i = 0; i < k + 1; i++)
        select[9 - i] = true;

    long long maxNum = 0;
    long long minNum = 9876543210;

    do {
        int selected[k + 1];
        for (int i = 0, si = 0; i < 10; i++)
            if (select[i]) selected[si++] = i;

        do {
            bool ok = true;
            long long num = 0;

            for (int i = 0; i < k; i++) {
                if (!check(signs[i], selected[i], selected[i + 1])) {
                    ok = false;
                    break;
                }
                num = num * 10 + selected[i];
            }

            if (ok) {
                num = num * 10 + selected[k];
                maxNum = max(maxNum, num);
                minNum = min(minNum, num);
            }
        } while (next_permutation(selected, selected + k + 1));
    } while (next_permutation(select, select + 10));

    print_ans_format(maxNum, k);
    print_ans_format(minNum, k);

    return 0;
}