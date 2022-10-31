#include <iostream>
#include <vector>
using namespace std;

struct node {
    int left, right;
};

int col = 0;
int depth = 1;
node tree[10001];
vector<int> lr[10001];

void set_node(int cur, int cur_level)
{
    if (tree[cur].left == -1 && tree[cur].right == -1) {
        lr[cur_level].push_back(col++);
        depth = max(depth, cur_level);
        return;
    }
    if (tree[cur].left != -1) set_node(tree[cur].left, cur_level + 1);
    lr[cur_level].push_back(col++);
    if (tree[cur].right != -1) set_node(tree[cur].right, cur_level + 1);
}

int main(void)
{
    int n;
    cin >> n;

    int parent_count[10001] = {0};
    for (int i = 0; i < n; i++) {
        int cur, left, right;
        cin >> cur >> left >> right;
        tree[cur].left = left;
        tree[cur].right = right;

        if (left != -1) parent_count[left] += 1;
        if (right != -1) parent_count[right] += 1;
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (parent_count[i] == 0) {
            root = i;
            break;
        }
    }

    set_node(root, 1);

    int max_level = 1;
    int max_width = 1;
    for (int i = 1; i <= depth; i++) {
        int cur_width = *(lr[i].end() - 1) - *(lr[i].begin()) + 1;
        if (max_width < cur_width) {
            max_level = i;
            max_width = cur_width;
        }
    }

    cout << max_level << ' ' << max_width;

    return 0;
}