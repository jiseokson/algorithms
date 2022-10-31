#include <iostream>
#include <utility>
using namespace std;

pair<int, int> memo[1001];

int main(void)
{
    int n;
    cin >> n;

    int * al = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        al[i] = a;
    }

    memo[0] = make_pair(-1, 1);
    int ans = 0;
    int ansi = 0;
    for (int i = 0; i < n; i++) {
        memo[i] = make_pair(-1, 1);
        for (int j = i - 1; j >= 0; j--) {
            if (al[j] < al[i] && memo[i].second < memo[j].second + 1)
                memo[i] = make_pair(j, memo[j].second + 1);
        }

        if (ans < memo[i].second) {
            ansi = i;
            ans = memo[i].second;
        }
    }

    cout << ans << '\n';

    string anss = to_string(al[ansi]);
    while (memo[ansi].first != -1) {
        anss =  to_string(al[memo[ansi].first]) + " " + anss;
        ansi = memo[ansi].first;
    }
    cout << anss;

    delete []al;
    return 0;
}