#include <iostream>
#include <vector>

using namespace std;

class MatrixRow {
public:
    MatrixRow(int col): row(col, 0.0) {}
    double& operator[](int i) { return row[i]; }
    const double& operator[](int i) const { return row[i]; }

private:
    vector<double> row;
};

class Matrix {
public:
    const int row, col;
    Matrix(int row, int col): row(row), col(col), mat_(row, MatrixRow(col)) {}

    friend ostream& operator<<(ostream& os, const Matrix &mat);

    MatrixRow& operator[](int i) { return mat_[i]; }
    const MatrixRow& operator[](int i) const { return mat_[i]; }

    Matrix operator*(const Matrix &rhs) {
        if (this -> col != rhs.row)
            throw out_of_range("Multiplication can\'t be performed.");
        
        Matrix res(this -> row, rhs.col);
        for (int i = 0; i < res.row; ++i)
            for (int j = 0; j < res.col; ++j)
                for (int k = 0; k < this -> col; ++k)
                    res[i][j] += (*this)[i][k] * rhs[k][j];
        return res;
    }

    Matrix pow(int n) {
        if (row != col)
            throw out_of_range("Exponent can\'t be performed.");

        Matrix res(row, row);
        if (n == 0) {
            for (int i = 0; i < row; ++i) res[i][i] = 1.0;
            return res;
        }

        Matrix pow_half = pow(n / 2);
        return n % 2 == 0? pow_half * pow_half: pow_half * pow_half * (*this);
    }

private:
    vector<MatrixRow> mat_;
};

ostream& operator<<(ostream& os, const Matrix &mat) {
    for (int i = 0; i < mat.row; ++i) {
        os << endl;
        for (int j = 0; j < mat.col; ++j)
            os << mat[i][j] << ' ';
    }
    return os;
}

int main(void) {
    Matrix a(2, 2);
    a[0][0] = a[1][1] = 2;

    Matrix b(2, 4);
    b[0][1] = b[1][0] = 3;
    b[0][0] = 2;
    b[1][2] = b[1][3] = 1;

    Matrix c(3, 2);
    c[0][0] = c[1][1] = 2;

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    cout << endl;

    try {
        cout << "a * b: " << a * b << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "a * c: " << a * c << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    cout << endl;

    try {
        cout << "a^3: " << a.pow(3) << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    try {
        cout << "b^3: " << b.pow(3) << endl;
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    return 0;
}