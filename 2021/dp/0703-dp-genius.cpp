#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<int> vi;

class MatrixRow {
public:
    vd row;
    const int col;
    MatrixRow(int col): col(col), row(col, 0.0) {};
    double& operator[](int i) { return row[i]; }
};

class Matrix {
    public:
    vector<MatrixRow> mat;
    const int row, col;

    Matrix(int row, int col): row(row), col(col), mat(row, MatrixRow(col)) {}

    MatrixRow& operator[](int i) { return mat[i]; }

    Matrix operator*(Matrix& rhs) {
        Matrix res(row, rhs.col);
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < rhs.col; ++j)
                for (int k = 0; k < col; ++k)
                    res[i][j] += (*this)[i][k] * rhs[k][j];
        return res;
    }

    Matrix pow(int n) {
        if (row != col) return Matrix(1, 1);

        Matrix res(row, row);
        if (n == 0) {
            for (int i = 0; i < row; ++i) res[i][i] = 1.0;
            return res;
        }

        Matrix temp = pow(n / 2);
        return n % 2 == 0? temp * temp: temp * temp * (*this);
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(8);

    int c;
    cin >> c;

    while (c--) {
        int n, k, m;
        cin >> n >> k >> m;
        vi L(n);
        Matrix T(n, n);

        for (int i = 0; i < n; ++i) cin >> L[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> T[i][j];

        Matrix W(4 * n, 4 * n);
        Matrix m0(4 * n, 1);
        m0[0][0] = 1.0;
        for (int r = 0; r < 3 * n; ++r) W[n + r][r] = 1.0;
        for (int prev = 0; prev < n; ++prev)
            for (int next = 0; next < n; ++next)
                W[next][(L[prev] - 1) * n + prev] = T[prev][next];
        Matrix ans = W.pow(k) * m0;

        for (int i = 0; i < m; ++i) {
            int q;
            cin >> q;
            double res = 0.0;
            for (int j = 0; j < L[q]; ++j)
                res += ans[n * j + q][0];
            cout << res << ' ';
        }
        cout << '\n';
    }

    return 0;
}