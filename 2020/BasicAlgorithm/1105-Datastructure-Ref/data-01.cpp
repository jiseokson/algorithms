#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    double num[26] = {0};
    string exp;

    cin >> n >> exp;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    stack<double> s;
    for (int i = 0, len = exp.length(); i < len; i++) {
        char cur = exp[i];
        if ('A' <= cur && cur <= 'Z')
            s.push(num[cur - 'A']);
        else {
            double rhs = s.top(); s.pop();
            double lhs = s.top(); s.pop();
            double res = 0;
            switch (cur) {
            case '+':
                res = lhs + rhs;
                break;
            case '-':
                res = lhs - rhs;
                break;
            case '*':
                res = lhs * rhs;
                break;
            case '/':
                res = lhs / rhs;
                break;
            }
            s.push(res);
        }
    }

    printf("%.2f\n", s.top());
    return 0;
}