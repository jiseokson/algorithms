#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    string s;
    cin >> s;

    stack<char> left, right;
    for (char c : s) {
        
    }

    int t;
    cin >> t;

    // int c = s.length();
    // string buf;
    while (t--) {
        char cmd;
        cin >> cmd;

        switch (cmd) {
        case 'L':
            if (c > 0) {
                buf += s.back();
                s.pop_back();
                c--;
            }
            break;

        case 'D':
            if (c < s.length() || buf.length() > 0) {
                s += buf.back();
                buf.pop_back();
                c++;
            }
            break;

        case 'B':
            if (c > 0) {
                s.pop_back();
                c--;
            }
            break;

        case 'P':
            char nc;
            cin >> nc;
            s += nc;
            c++;
            break;
        }
    }

    string rbuf;
    for (char c : buf) {
        rbuf += c;
    }
    while (rbuf.length() > 0) {
        s += rbuf.back();
        rbuf.pop_back();
    }

    cout << s;
    return 0;
}