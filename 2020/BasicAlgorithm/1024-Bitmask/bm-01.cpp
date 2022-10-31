#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, bm = 0;
    cin >> m;

    while (m--) {
        string command;
        cin >> command;

        if (command == "add") {
            int e;
            cin >> e;
            bm |= 1 << e;
        } else if (command == "remove") {
            int e;
            cin >> e;
            bm &= ~(1 << e);
        } else if (command == "check") {
            int e;
            cin >> e;
            cout << (bm & (1 << e) ? 1 : 0) << '\n';
        } else if (command == "toggle") {
            int e;
            cin >> e;
            bm ^= 1 << e;
        } else if (command == "all") {
            bm = -1;
        } else if (command == "empty") {
            bm = 0;
        }
    }
    return 0;
}