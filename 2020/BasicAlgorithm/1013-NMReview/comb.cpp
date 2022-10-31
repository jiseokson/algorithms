#include <iostream>
#include <ctime>
using namespace std;

int n, k;
int arr[100];

void comb1(int i, int begin)
{
    if (i == k) {
        for (int j = 0; j < k; j++)
            cout << arr[j] << ' ';
        cout << '\n';
        return;
    }

    for (int j = begin; j < n; j++) {
        arr[i] = j;
        comb1(i + 1, j + 1);
    }
}

void comb2(int i, int target)
{
    if (i == k) {
        for (int j = 0; j < k; j++)
            cout << arr[j] << ' ';
        cout << '\n';
        return;
    }

    if (target >= n)
        return;

    arr[i] = target;
    comb2(i + 1, target + 1);
    arr[i] = 0;
    comb2(i, target + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    clock_t beginTime, endTime;
    cin >> n >> k;

    beginTime = clock();
    comb1(0, 0);
    endTime = clock();
    double comb1RunningTime = (double)(endTime - beginTime) / CLOCKS_PER_SEC;

    beginTime = clock();
    comb2(0, 0);
    endTime = clock();
    double comb2RunningTime = (double)(endTime - beginTime) / CLOCKS_PER_SEC;

    cout << "comb1 running time = " << comb1RunningTime << '\n';
    cout << "comb2 running time = " << comb2RunningTime << '\n';

    return 0;
}