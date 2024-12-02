#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

struct Node {
    int value;
    int height;
    Node *left;
    Node *right;
    Node(int val, int h = 0, Node *left_ptr = nullptr, Node *right_ptr = nullptr) {
        value = val;
        height = h;
        left = left_ptr;
        right = right_ptr;
    }
};

struct AVLTree {
    Node *root = nullptr;

    int h(Node *root) {
        if (root == nullptr) return -1;
        return root->height;
    }

    int get_balance(Node *root) {
        if (root == nullptr) return 0;
        return h(root->left) - h(root->right);
    }

    Node *right_rotate(Node *root) {
        Node *l = root->left;
        Node *lr = l->right;
        l->right = root;
        root->left = lr;
        root->height = max(h(root->left), h(root->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        return l;
    }

    Node *left_rotate(Node *root) {
        Node *r = root->right;
        Node *rl = r->left;
        r->left = root;
        root->right = rl;
        root->height = max(h(root->left), h(root->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;
        return r;
    }

    Node *insert_help(Node *root, int value) {
        if (root == nullptr) {
            return new Node(value);
        } else if (value < root->value) {
            root->left = insert_help(root->left, value);
        } else {
            root->right = insert_help(root->right, value);
        }

        root->height = 1 + max(h(root->left), h(root->right));
        int balance = get_balance(root);

        if (balance < -1) {
            if (value >= root->right->value) {
                return left_rotate(root);
            } else {
                root->right = right_rotate(root->right);
                return left_rotate(root);
            }
        }

        if (balance > 1) {
            if (value < root->left->value) {
                return right_rotate(root);
            } else {
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
        }

        return root;
    }

    void insert(int value) {
        root = insert_help(root, value);
    }

    void pre_order_help(Node *root) {
        if (root == nullptr) return;

        cout << root->value << '\n';
        pre_order_help(root->left);
        pre_order_help(root->right);
    }

    void pre_order() {
        pre_order_help(root);
        cout << "END\n";
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc, n, u;
    cin >> tc;
    while (tc--) {
        cin >> n;
        AVLTree tree;
        for (int i = 0; i < n; i++) {
            cin >> u;
            tree.insert(u);
        }

        tree.pre_order();
    }

    return 0;
}