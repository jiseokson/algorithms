#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

vi to_vi(const string& str) {
    vi a;
    for (int i = 0; i < str.length(); ++i)
        a.push_back(str[i] == 'F'? 0: 1);
    return a;
}

void normalize(vi& num) {
    num.push_back(0);
    for (int i = 0; i + 1 < num.size(); ++i) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while (num.size() > 1 && num.back() == 0) num.pop_back();
}

void add_to(vi& a, const vi& b, int k) {
    // a += b * 10^k
    a.resize(max(a.size(), b.size() + k) + 1, 0);
    for (int i = 0; i < b.size(); ++i)
        a[i + k] += b[i];
    normalize(a);   
}

void sub_from(vi& a, const vi& b) {
    // a >= b 가정, a -= b
    for (int i = 0;  i < b.size(); ++i)
        a[i] -= b[i];
    normalize(a);
}

vi multiply(const vi& a, const vi& b) {
    vi product(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
            product[i + j] += a[i] * b[j];
    normalize(product);
    return product;
}

vi karatsuba(const vi& a, const vi& b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vi(1, 0);
    if (an <= 20) return multiply(a, b);

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
        reverse(members.begin(), members.end());
        vi result = karatsuba(to_vi(members), to_vi(fans));
        result.resize(members.length() + fans.length() - 1, 0);
        cout << count_zero(result, members.length() - 1, result.size() - members.length()) << '\n';
    }

    return 0;
}