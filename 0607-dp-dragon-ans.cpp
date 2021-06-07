#include <iostream>

using namespace std;

void dragon(string seed, int gen) {
    if (gen == 0) {
        cout << seed;
        return ;
    }

    for (char c : seed) {
        if (c == 'X') dragon("X+YF", gen - 1);
        else if (c == 'Y') dragon("FX-Y", gen - 1);
        else cout << c;
    }
}

int main(void) {
    while (true) {
        int g;
        cin >> g;
        dragon("FX", g);
        cout << '\n';
    }
    return 0;
}