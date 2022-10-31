#include <iostream>
#include <vector>
using namespace std;

vector<int> v(10);

int main(void)
{
    cout << v.size() << '\n';
    v.push_back(10);
    cout << v.size() << '\n';

    return 0;
}