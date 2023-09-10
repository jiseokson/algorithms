#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

using vi = vector<int>;

inline void print_arr(vi& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << ' ';
    cout << '\n';
}

int recur_sum(int n) {
    if (n == 1) return 1;
    return n + recur_sum(n - 1);
}

void pick1(int n, int k, vi& picked) {
    if (picked.size() == k) {
        print_arr(picked);
        return;
    }
    for (int next = picked.empty()? 0: picked.back() + 1; next < n; ++next) {
        picked.push_back(next);
        pick1(n, k, picked);
        picked.pop_back();
    }
}

void pick2(int n, int k, int s, vi& picked) {
    if (picked.size() == k) {
        print_arr(picked);
        return;
    }
    if (s >= n)
        return;
    picked.push_back(s);
    pick2(n, k, s + 1, picked);
    picked.pop_back();
    pick2(n, k, s + 1, picked);
}

int main(void) {
    int n = 20, k = 15;
    time_t start, end;

    vi picked1;
    cout << "pick1\n";
    start = clock();
    pick1(n, k, picked1);
    end = clock();
    time_t pick1_duration = end - start;

    vi picked2;
    cout << "pick2\n";
    start = clock();
    pick2(n, k, 0, picked2);
    end = clock();
    time_t pick2_duration = end - start;

    cout << "pick1 duration: " << pick1_duration << '\n';
    cout << "pick2 duration: " << pick2_duration << '\n';

    return 0;
}