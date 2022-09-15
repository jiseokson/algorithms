#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

void add_to(vi& a, const vi& b, int k) {
    // a += b * 10^k
    a.resize(max(a.size(), b.size() + k) + 1, 0);
    for (int i = 0; i < b.size(); ++i)
        a[i + k] += b[i];
}

void sub_from(vi& a, const vi& b) {
    // a >= b 가정, a -= b
    for (int i = 0;  i < b.size(); ++i)
        a[i] -= b[i];
}

vi multiply(const vi& a, const vi& b) {
    vi product(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            product[i + j] += a[i] * b[j];
    return product;
}

vi karatsuba(const vi& a, const vi& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vi(1, 0);
    if (an <= 50) return multiply(a, b);

    int half = an / 2;
    vi a0 = vi(a.begin(), a.begin() + half);
    vi a1 = vi(a.begin() + half, a.end());
    vi b0 = vi(b.begin(), b.begin() + min<int>(half, b.size()));
    vi b1 = vi(b.begin() + min<int>(half, b.size()), b.end());

    vi z0 = karatsuba(a0, b0);
    vi z2 = karatsuba(a1, b1);
    add_to(a0, a1, 0);
    add_to(b0, b1, 0);
    vi z1 = karatsuba(a0, b0);
    sub_from(z1, z0);
    sub_from(z1, z2);

    vi ret = vi(1, 0);
    add_to(ret, z0, 0);
    add_to(ret, z1, half);
    add_to(ret, z2, 2 * half);
    return ret;
}

int count_zero(const vi& a, int lo, int hi) {
    int ret = 0;
    for (int i = lo; i <=hi; ++i)
        if (a[i] == 0)
            ++ret;
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        string members, fans;
        cin >> members >> fans;

        vi m(members.length()), f(fans.length());
        for (int i = 0; i < m.size(); ++i) m[m.size() - i - 1] = (members[i] == 'M');
        for (int i = 0; i < f.size(); ++i) f[i] = (fans[i] == 'M');

        vi result = karatsuba(m, f);
        result.resize(members.length() + fans.length() - 1, 0);
        cout << count_zero(result, members.length() - 1, fans.length() - 1) << '\n';
    }

    return 0;
}