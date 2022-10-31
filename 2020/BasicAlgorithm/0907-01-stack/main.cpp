#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int max;
    cin >> max;

    stack<int> buf;
    string ans;
    int n = 1;

    for (int i = 0; i < max; i++) {
        int newNum;
        cin >> newNum;

        if (buf.size() == 0 || buf.top() != newNum) {
            do {
                if (n > max) {
                    cout << "NO\n";
                    return 0;
                }
                
                buf.push(n++);
                ans += "+\n";
            } while (buf.top() != newNum);
        }

        buf.pop();
        ans += "-\n";
    }

    cout << ans;
    return 0;
}