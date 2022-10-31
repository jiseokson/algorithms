#include <iostream>
using namespace std;

int al[1001];
int memo[1001];
int w[1001];

int main(void)
{
    int n;
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        al[i] = a;
    }

    int ans = 0, ansi = 0;
    for (int i = 0; i < n; i++) {
        memo[i] = 1;
        w[i] = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (al[j] < al[i] && memo[i] < memo[j] + 1) {
                memo[i] = memo[j] + 1;
                w[i] = j;
            }
        }
        
        if (ans < memo[i]) {
            ans = memo[i];
            ansi = i;
        }
    }

    cout << ans << '\n';

    string anss = to_string(al[ansi]);
    while (w[ansi] != -1) {
        anss = to_string(al[w[ansi]]) + ' ' + anss;
        ansi = w[ansi];
    }

    cout << anss;

    return 0;
}