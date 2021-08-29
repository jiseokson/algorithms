#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct Node {
    int x, y, r;
    vector<Node*> child;
};

inline int square(int a) {
    return a * a;
}

inline bool enclose(Node *a, Node *b) {
    return square(a->x - b->x) + square(a->y - b->y) < square(a->r - b->r);
}

Node *getTree(int n) {
    Node *root = new Node();
    cin >> root->x >> root->y >> root->r;
    vector<Node*> nodes(1, root);
    for (int i = 1; i < n; ++i) {
        Node *newNode = new Node();
        cin >> newNode->x >> newNode->y >> newNode->r;
        Node *parent = root;
        for (Node *parentCand: nodes)
            if (enclose(parent, parentCand) && enclose(parentCand, newNode))
                parent = parentCand;
        parent->child.push_back(newNode);
        nodes.push_back(newNode);
    }
    return root;
}

void deleteTree(Node *tree) {
    for (Node *c: tree->child)
        deleteTree(c);
    delete tree;
}

int depth(Node *node) {
    if (node == nullptr) return 0;
    int d = 0;
    for (Node *c: node->child) d = max(d, depth(c) + 1);
    return d;
}

int maxLen(Node *root) {
    vector<int> depths;
    for (Node *c: root->child) depths.push_back(depth(c) + 1);
    sort(depths.begin(), depths.end());
    if (depths.size() > 1) return *(depths.rbegin()) + *(depths.rbegin() + 1);
    return *depths.rbegin();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        Node *root = getTree(n);
        cout << maxLen(root) << '\n';
        deleteTree(root);
    }

    return 0;
}