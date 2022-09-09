#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

bool is_sorted(const vi& arr) {
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}

int count_obvious(int n) {
    int count = 0;
    for (int x = 1; x <= n; ++x) {
        double y = 1.0 / x;
        if (y * x == 1.0)
            ++count;
    }
    return count;
}

// inline bool absolute_equal(double a, double b) {
//     return fabs(a - b) < 1e-10;
// }

int main(void) {
    unsigned char a = 17;
    short b = -18;
    int c = 2;
    unsigned int d = 0;
    cout << (a + b) * c + d << endl;

    vi arr(0);
    cout << is_sorted(arr) << '\n';

    cout << count_obvious(50) << '\n';

    return 0;
}