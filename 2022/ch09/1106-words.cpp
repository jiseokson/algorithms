#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;

vi cnt; // cnt[i] = sigma(5^j, 0 <= j <= i)

string kth(int n, int k) // 길이 0 ~ 5사이인 단어들 중 사전식 순서로 k번째 단어
{
    if (k == 0) return "";
    --k;
    return "AEIOU"[k / cnt[n - 1]] + kth(n - 1, k % cnt[n - 1]);
    // for (char c: {'A', 'E', 'I', 'O', 'U'}) {
    //     if (k < cnt[n - 1])
    //         return c + kth(n - 1, k);
    //     k -= cnt[n - 1];
    // }
}

int power(int n, int i)
{
    if (i == 0) return 1;
    return n * power(n, i - 1);
}

string kth2(int n, int k) // 길이 5인 단어들 중 사전식 순서로 k번재 단어
{
    if (n == 0) return "";
    return "AEIOU"[k / power(5, n - 1)] + kth2(n - 1, k % power(5, n - 1));
    // for (char c: {'A', 'E', 'I', 'O', 'U'}) {
    //     if (k < power(5, n - 1))
    //         return c + kth2(n - 1, k);
    //     k -= power(5, n - 1);
    // }
    // return "";
}

int main(void)
{
    cnt = vi(6, 1);
    for (int i = 1; i <= 5; ++i)
        cnt[i] = cnt[i - 1] * 5 + 1;
    for (int i = 0;  i < 100; ++i)
        cout << kth2(5, i) << endl;
    return 0;
}