#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int inef_maxsum(vi& arr) {
    int maxsum = arr[0];
    for (int i = 0; i < arr.size(); ++i) {
        int sum = 0;
        for (int j = i; j < arr.size(); ++j) {
            sum += arr[j];
            maxsum = max(sum, maxsum);
        }
    }
    return maxsum;
}

int dnc_maxsum(vi& arr, int lo, int hi) {
    // 답이 되는 부분구간이 
    // 1) mid, mid + 1을 포함하는 경우
    // 2) [lo, mid]에 속하는 경우
    // 3) [mid + 1, hi]에 속하는 경우
    // 1), 2), 3) 중 최대값 반환
    if (lo == hi) return arr[lo];
    int mid = (lo + hi) / 2;

    int left = arr[mid], right = arr[mid + 1];
    int sum = 0;
    for (int i = mid; i >= lo; --i) {
        sum += arr[i];
        left = max(sum, left);
    }
    sum = 0;
    for (int i = mid + 1; i <= hi; ++i) {
        sum += arr[i];
        right = max(sum, right);
    }

    return max(
        left + right,
        max(dnc_maxsum(arr, lo, mid), dnc_maxsum(arr, mid + 1, hi))
    );
}

int dp_maxsum(vi& arr) {
    // dp[i]: arr[i]를 오른쪽 끝으로 가지는 부분구간의 최대합
    // dp[i] = max(dp[i - 1], 0) + arr[i]
    // 최대합은 max(dp[i])
    int maxsum = arr[0], psum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        psum = max(psum, 0) + arr[i];
        maxsum = max(maxsum, psum);
    }
    return maxsum;
}

int main(void) {
    vi arr = {-7, 4, -3, 6, 3, -8, 3, 4};
    cout << "inef: " << inef_maxsum(arr) << '\n';
    cout << "dnc: " << dnc_maxsum(arr, 0, arr.size() - 1) << '\n';
    cout << "dp: " << dp_maxsum(arr) << '\n';
    return 0;
}