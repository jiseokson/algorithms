#include <iostream>
#include <stack>
using namespace std;

inline int op_order(char op)
{
    int res = 0;
    switch (op) {
    case '(':
        res = 0;
        break;
    case '+':
    case '-':
        res = 1;
        break;
    case '*':
    case '/':
        res = 2;
        break;
    }
    return res;
}

int main(void)
{
    string infix_exp, postfix_exp = "";
    cin >> infix_exp;

    stack<char> ops;
    for (int i = 0, len = infix_exp.length(); i < len; i++) {
        char cur = infix_exp[i];

        if ('A' <= cur && cur <= 'Z')
            postfix_exp += cur;
        else {
            if (cur == '(')
                ops.push(cur);
            else if (cur == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    postfix_exp += ops.top();
                    ops.pop();
                }
                ops.pop();
            } else {
                while (!ops.empty() && op_order(cur) <= op_order(ops.top())) {
                    postfix_exp += ops.top();
                    ops.pop();
                }
                ops.push(cur);
            }
        }
    }

    while (!ops.empty()) {
        postfix_exp += ops.top();
        ops.pop();
    }

    cout << postfix_exp;

    return 0;
}