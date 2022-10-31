#include <iostream>
using namespace std;

int main(void)
{
    string ans = "<";
    bool kf[5000] = {0};
    int n, k;
    cin >> n >> k;

    int kc = 0;
    int i = 0;
    while (true) {
        for (int j = 0; j < k - 1; j++) {
            do {
                i = (i + 1) % n;
            } while (kf[i] != false);
        }

        kf[i] = true;
        kc++;
        ans = ans + to_string(i + 1) + ", ";

        if (kc < n) {
            do {
                i = (i + 1) % n;
            } while (kf[i] != false);
        } else {
            break;
        }

    }

    ans.pop_back();
    ans.pop_back();
    cout << ans << ">\n";
    
    return 0;
}