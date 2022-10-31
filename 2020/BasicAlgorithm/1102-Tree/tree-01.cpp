#include <iostream>
using namespace std;

struct node {
    char data;
    int left, right;
};

node tree[50];

void preorder_traversal(int cur)
{
    if (tree[cur].left == -1 && tree[cur].right == -1) {
        cout << tree[cur].data;
        return;
    }
    cout << tree[cur].data;
    if (tree[cur].left != -1) preorder_traversal(tree[cur].left);
    if (tree[cur].right != -1)preorder_traversal(tree[cur].right);
}

void inorder_traversal(int cur)
{
    if (tree[cur].left == -1 && tree[cur].right == -1) {
        cout << tree[cur].data;
        return;
    }
    if (tree[cur].left != -1) inorder_traversal(tree[cur].left);
    cout << tree[cur].data;
    if (tree[cur].right != -1)inorder_traversal(tree[cur].right);
}

void postorder_traversal(int cur)
{
    if (tree[cur].left == -1 && tree[cur].right == -1) {
        cout << tree[cur].data;
        return;
    }
    if (tree[cur].left != -1) postorder_traversal(tree[cur].left);
    if (tree[cur].right != -1) postorder_traversal(tree[cur].right);
    cout << tree[cur].data;
}

int main(void)
{
    int n;
    cin >> n;
    
    while (n--) {
        char cur_data, left_data, right_data;
        cin >> cur_data >> left_data >> right_data;

        tree[cur_data - 'A'].data = cur_data;

        if (left_data == '.' && right_data == '.') {
            tree[cur_data - 'A'].left = -1;
            tree[cur_data - 'A'].right = -1;
        } else if (left_data == '.') {
            tree[cur_data - 'A'].left = -1;
            tree[cur_data - 'A'].right = right_data - 'A';
        } else if (right_data == '.') {
            tree[cur_data - 'A'].left = left_data - 'A';
            tree[cur_data - 'A'].right = -1;
        } else {
            tree[cur_data - 'A'].left = left_data - 'A';
            tree[cur_data - 'A'].right = right_data - 'A';
        }
    }

    preorder_traversal(0);
    cout << '\n';
    inorder_traversal(0);
    cout << '\n';
    postorder_traversal(0);
    cout << '\n';

    return 0;
}