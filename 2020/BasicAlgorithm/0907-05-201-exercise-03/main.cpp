#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    stack<int> is, buf, ans;
    int t;

    cin >> t;
    while (t--) {
        int nn;
        cin >> nn;
        is.push(nn);
    }

    while (!is.empty()) {
        int n = is.top();
        is.pop();

        if (buf.empty()) {
            ans.push(-1);
            buf.push(n);
        } else {
            if (n < buf.top()) {
                ans.push(buf.top());
                buf.push(n);
            } else {
                while (!buf.empty() && n >= buf.top()) {
                    buf.pop();
                }

                if (buf.empty()) {
                    ans.push(-1);
                    buf.push(n);
                } else {
                    ans.push(buf.top());
                    buf.push(n);
                }
            }
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}