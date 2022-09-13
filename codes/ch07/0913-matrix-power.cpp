#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void print_matrix(const vvi& a) {
    const int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

vvi unit_matrix(int n) {
    vvi um = vvi(n, vi(n, 0));
    for (int i = 0; i < n; ++i)
        um[i][i] = 1;
    return um;
}

vvi matrix_product(const vvi& a, const vvi& b) {
    const int n = a.size();
    vvi product(n, vi(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                product[i][j] += a[i][k] * b[k][j];
    return product;
}

vvi matrix_pow(const vvi& a, const int n) {
    if (n == 0) return unit_matrix(a.size());
    if (n % 2 == 1) return matrix_product(a, matrix_pow(a, n - 1));
    vvi half = matrix_pow(a, n / 2);
    return matrix_product(half, half);
}

int main(void) {
    vvi a = {
        {1, 2},
        {3, 4}
    };
    print_matrix(a);
    print_matrix(matrix_pow(a, 10));
    return 0;
}