#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    string str;
    stack<int> lcs;
    int ans = 0;
    bool isLaser = true;

    cin >> str;

    for (char c : str) {
        if (c == '(') {
            lcs.push(0);
            isLaser = true;
        } else {
            if (isLaser) {
                lcs.pop();
                lcs.push(1);
                isLaser = false;
            } else {
                int nc = 0;
                while (lcs.top() != 0) {
                    nc += lcs.top();
                    lcs.pop();
                }
                lcs.pop();
                lcs.push(nc);
                ans += nc + 1;
            }
        }
    }

    cout << ans;
    return 0;
}