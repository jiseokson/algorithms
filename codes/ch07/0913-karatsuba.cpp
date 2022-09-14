#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

using vi = vector<int>;

vi to_vi(int n) {
    vi num;
    do {
        num.push_back(n % 10);
        n /= 10;
    } while (n);
    return num;
}

string to_string(const vi& num) {
    // num 정규화 가정
    string num_str = "";
    for (int i = num.size() - 1; i >= 0; --i)
        num_str += num[i] + '0';
    return num_str;
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
    if (an == 0 || bn == 0) return to_vi(0);
    if (an <= 2) return multiply(a, b);

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

    vi ret = to_vi(0);
    add_to(ret, z0, 0);
    add_to(ret, z1, half);
    add_to(ret, z2, 2 * half);
    return ret;
}

int main(void) {
    int test_case = 10;
    int digit_len = 50;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 9);
    for (int i = 0; i < test_case; ++i) {
        vi a, b;
        for (int j = 0; j < digit_len; ++j) {
            a.push_back(dis(gen));
            b.push_back(dis(gen));
        }
        cout << "Test case #" << i << '\n';
        cout << "a: " << to_string(a) << '\n';
        cout << "b: " << to_string(b) << '\n';
        cout << "a*b: " << to_string(karatsuba(a, b)) << "\n\n";
    }

    return 0;
}