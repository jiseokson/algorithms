#include <iostream>
using namespace std;

int brokenKey[10];
int bkCount = 0;

inline bool isGo(int dest)
{
    if (dest == 0) {
        for (int i = 0; i < bkCount; i++) {
            if (brokenKey[i] == 0)
                return false;
        }
        return true;
    }

    while (dest > 0) {
        int u = dest % 10;
        for (int i = 0; i < bkCount; i++) {
            if (brokenKey[i] == u)
                return false;
        }
        dest /= 10;
    }
    return true;
}

inline int len(int n)
{
    if (n == 0)
        return 1;

    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

int main(void)
{
    int dest;
    cin >> dest;
    cin >> bkCount;
    for (int i = 0; i < bkCount; i++) {
        int bk;
        cin >> bk;
        brokenKey[i] = bk;
    }

    int ans = dest > 100 ? dest - 100 : 100 - dest;

    if (bkCount == 10) {
        cout << ans;
        return 0;
    }

    if (isGo(dest)) {
        int l = len(dest);
        if (ans > l)
            ans = l;
    }

    for (int i = 0; ; i++) {
        if (0 <= dest - i && isGo(dest - i)) {
            int l = len(dest - i);
            if (ans > l + i)
                ans = l + i;
            break;
        } else if (isGo(dest + i)) {
            int l = len(dest + i);
            if (ans > l + i)
                ans = l + i;
            break;
        }
    }

    cout << ans;
    return 0;
}