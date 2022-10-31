#include <iostream>
using namespace std;

int to_unit(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

int main(void)
{
    string n;
    int b;
    cin >> n >> b;

    int ans = 0;
    for (char u : n) {
        ans = ans * b + to_unit(u);
    }

    cout << ans;
    return 0;
}