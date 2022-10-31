#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> adj_list[n];
    for (int i = 0; i < m; i++) {
        int person1, person2;
        cin >> person1 >> person2;
        adj_list[person1].push_back(person2);
        adj_list[person2].push_back(person1);
    }

    for (int i = 0; i < n; i++) {
        //
    }
    return 0;
}