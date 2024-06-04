#include <iostream>

using namespace std;
using ll = long long;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int dada, Node *lc = nullptr, Node *rc = nullptr) {
        data = dada;
        left = lc;
        right = rc;
    }
};

struct BST {
    Node *insert_helper(Node *root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        if (data < root->data) {
            root->left = insert_helper(root->left, data);
        } else {
            root->right = insert_helper(root->right, data);
        }

        return root;
    }

    Node *root = nullptr;

    void insert(int data) {
        root = insert_helper(root, data);
    }

    void pre_order(Node *root, void (*visitor)(int)) {
        if (root == nullptr) return;
        visitor(root->data);
        pre_order(root->left, visitor);
        pre_order(root->right, visitor);
    }
    void in_order(Node *root, void (*visitor)(int)) {
        if (root == nullptr) return;
        in_order(root->left, visitor);
        visitor(root->data);
        in_order(root->right, visitor);
    }
    void post_order(Node *root, void (*visitor)(int)) {
        if (root == nullptr) return;
        post_order(root->left, visitor);
        post_order(root->right, visitor);
        visitor(root->data);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    BST tree;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        tree.insert(k);
    }

    cout << "Pre order :";
    tree.pre_order(tree.root, [](int n) {
        cout << ' ' << n;
    });
    cout << '\n';

    cout << "In order  :";
    tree.in_order(tree.root, [](int n) {
        cout << ' ' << n;
    });
    cout << '\n';

    cout << "Post order:";
    tree.post_order(tree.root, [](int n) {
        cout << ' ' << n;
    });

    return 0;
}