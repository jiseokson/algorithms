#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

struct Node {
    int x, y, r;
    vector<Node*> child;
};

int n;
vector<Node*> nodes;

inline int square(int a) {
    return a * a;
}

inline bool enclose(Node *a, Node *b) {
    // a->r >= b->r: a->r - b->r가 음수가 되는 경우가 있으므로
    return a->r >= b->r && square(a->x - b->x) + square(a->y - b->y) <= square(a->r - b->r);
}

bool isChild(int parentIdx, int childIdx) {
    if (!enclose(nodes[parentIdx], nodes[childIdx])) return false;
    for (int i = 0; i < n; ++i)
        if (i != parentIdx && i != childIdx && enclose(nodes[parentIdx], nodes[i]) && enclose(nodes[i], nodes[childIdx]))
            return false;
    return true;
}

Node *getTree(int rootIdx) {
    Node *root = nodes[rootIdx];
    for (int chIdx = 0; chIdx < n; ++chIdx)
        if (chIdx != rootIdx && isChild(rootIdx, chIdx))
            root->child.push_back(getTree(chIdx));
    return root;
}

void deleteTree(Node *tree) {
    for (Node *c: tree->child)
        deleteTree(c);
    delete tree;
}

int depth(Node *node) {
    int d = 0;
    for (Node *c: node->child) d = max(d, depth(c) + 1);
    return d;
}

int maxLen(Node *root) {
    vector<int> depths;
    for (Node *c: root->child) depths.push_back(depth(c) + 1);
    sort(depths.begin(), depths.end());
    if (depths.size() > 1) return *(depths.rbegin()) + *(depths.rbegin() + 1);
    if (depths.size() == 1) return depths[0];
    return 0;
}

void print(Node *tree, int d = 0) {
    for (int i = 0; i < d; ++i) cout << ' ' ;
    cout << tree->x << tree->y << tree->r << '\n';
    for (Node *c: tree->child) print(c, d + 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        nodes = vector<Node*>();
        for (int i = 0; i < n; ++i) {
            Node *newNode = new Node();
            cin >> newNode->x >> newNode->y >> newNode->r;
            nodes.push_back(newNode);
        }
        Node *tree = getTree(0);
        print(tree);
        cout << maxLen(tree) << '\n';
        deleteTree(tree);
    }

    return 0;
}