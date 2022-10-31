#include <iostream>
#include <vector>
using namespace std;

int n;
int stats[20][20];

vector<int> start;
vector<int> link;

int min_diff(int person)
{
    if (person == n) {
        if (start.size() != n / 2)
            return INT32_MAX;

        int startStats = 0;
        int linkStats = 0;
        for (int i = 0; i < n / 2 - 1; i++) {
            for (int j = i; j < n / 2; j++) {
                startStats += stats[start[i]][start[j]] + stats[start[j]][start[i]];
                linkStats += stats[link[i]][link[j]] + stats[link[j]][link[i]];
            }
        }

        return abs(startStats - linkStats);
    }

    if (start.size() > n / 2 || link.size() > n / 2)
        return INT32_MAX;

    int res = INT32_MAX;

    start.push_back(person);
    res = min(res, min_diff(person + 1));
    start.pop_back();

    link.push_back(person);
    res = min(res, min_diff(person + 1)) ;
    link.pop_back();

    return res;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stats[i][j];
        }
    }

    cout << min_diff(0);

    return 0;
}