#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int n;
vi preorder, inorder;

// struct Node {
//     int data;
//     Node *left, *right;
//     Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
// };

// Node *makeTree(int preI, int preJ, int inI, int inJ) {
//     if (preI > preJ) return nullptr;
//     if (preI == preJ) return new Node(preorder[preI], nullptr, nullptr);
//     int rootData = preorder[preI];
//     int leftSubSize = 0;
//     while (inorder[inI + leftSubSize] != rootData) ++leftSubSize;
//     return new Node(
//         rootData,
//         makeTree(preI + 1, preI + leftSubSize, inI, inI + leftSubSize - 1),
//         makeTree(preI + leftSubSize + 1, preJ, inI + leftSubSize + 1, inJ)
//     );
// }

void printPostorder(int preI, int preJ, int inI, int inJ) {
    if (preI > preJ) return;
    int rootData = preorder[preI];
    int leftSubSize = 0;
    while (inorder[inI + leftSubSize] != rootData) ++leftSubSize;
    printPostorder(preI + 1, preI + leftSubSize, inI, inI + leftSubSize - 1);
    printPostorder(preI + leftSubSize + 1, preJ, inI + leftSubSize + 1, inJ);
    cout << rootData << ' ';
}

// void postorder(Node *tree) {
//     if (tree == nullptr) return;
//     postorder(tree->left);
//     postorder(tree->right);
//     cout << tree->data << ' ';
// }

// void deleteTree(Node *tree) {
//     if (tree == nullptr) return;
//     deleteTree(tree->left);
//     deleteTree(tree->right);
//     delete tree;
// }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        preorder= vi(n), inorder = vi(n);
        for (int i = 0; i < n; ++i) cin >> preorder[i];
        for (int i = 0; i < n; ++i) cin >> inorder[i];
        printPostorder(0, n - 1, 0, n - 1);
        cout << '\n';
        // Node *tree = makeTree(0, n - 1, 0, n - 1);
        // postorder(tree);
        // cout << '\n';
        // deleteTree(tree);
    }

    return 0;
}