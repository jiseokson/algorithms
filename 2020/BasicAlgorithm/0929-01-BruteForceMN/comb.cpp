#include <iostream>
using namespace std;

int n, m;
int arr[10];

void comb(int target, int index)
{
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    if (target > n)
        return;

    arr[index] = target;
    comb(target + 1, index + 1);
    comb(target + 1, index);
}


int main(void)
{
    cin >> n >> m;
    comb(1, 0);
}