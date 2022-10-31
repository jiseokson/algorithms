#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 1;
    }

    for (int i = 2; n > 1; i++) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    
    return 0;
}