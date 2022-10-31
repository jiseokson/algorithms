#include <iostream>
using namespace std;

enum {LEFT, RIGHT, NONE};
int d[3][100001];

int lpos(int fl, int i)
{
    if (i == 0)
        return 1;
    if (d[fl][i] != 0)
        return d[fl][i];

    int res = 0;
    switch (fl) {
    case LEFT:
        res = (lpos(RIGHT, i - 1) + lpos(NONE, i - 1)) % 9901;
        break;
    case RIGHT:
        res = (lpos(LEFT, i - 1) + lpos(NONE, i - 1)) % 9901;
        break;
    case NONE:
        res = (lpos(LEFT, i - 1) + lpos(RIGHT, i - 1) + lpos(NONE, i - 1)) % 9901;
        break;
    }

    d[fl][i] = res;
    return res;
}

int main(void)
{
    int n;
    cin >> n;
    int ans = (lpos(LEFT, n - 1) + lpos(RIGHT, n - 1) + lpos(NONE, n - 1)) % 9901;
    cout << ans;
    return 0;
}