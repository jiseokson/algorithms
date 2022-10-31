#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    deque<int> dq;
    int t;
    cin >> t;

    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back") {
            int nn;
            cin >> nn;
            dq.push_back(nn);
        } else if (cmd == "push_front") {
            int nn;
            cin >> nn;
            dq.push_front(nn);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << '\n';
        } else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        } else if (cmd == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << '\n';
            }
        } else if (cmd == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << '\n';
            }
        } 
    }
    
    return 0;
}