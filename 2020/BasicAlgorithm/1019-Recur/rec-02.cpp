#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char chars[20];
char combs[20];

void allcomb(int index, int target)
{
    if (index >= l) {
        int vc = 0, cc = 0;
        for (int i = 0; i < l; i++) {
            if (combs[i] == 'a' || combs[i] == 'e' || combs[i] == 'i' || combs[i] == 'o' || combs[i] == 'u')
                vc++;
            else
                cc++;
            if (vc >= 1 && cc >= 2)
                break;
            if (i == l - 1)
                return;
        }
        combs[index] = '\0';
        cout << combs << '\n';
        return;
    }

    if (target >= c)
        return;

    combs[index] = chars[target];
    allcomb(index + 1, target + 1);
    allcomb(index, target + 1);
}

int main(void)
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> chars[i];
    sort(chars, chars + c);
    allcomb(0, 0);
    return 0;
}