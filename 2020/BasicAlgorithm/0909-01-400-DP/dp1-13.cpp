#include <iostream>
using namespace std;

int memo[100001] = {0};

int minsqn(int i)
{
    if (i == 0)
        return 0;
    if (memo[i] != 0)
        return memo[i];

    int res = 1 + minsqn(i - 1);;
    for (int j = 2; j * j <= i; j++) {
        int temp = 1 + minsqn(i - j * j);
        if (res > temp)
            res = temp;
    }
    
    memo[i] = res;
    return memo[i];
}

int main(void)
{
    int n;
    cin >> n;

    cout << minsqn(n);
    return 0;
}