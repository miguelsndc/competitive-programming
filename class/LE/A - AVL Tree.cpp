#include <iostream>

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

using namespace std;

class Node {
   public:
    int value;
    Node *left;
    Node *right;
    int height;
    int size = 1;
    Node(int val, Node *leftv = nullptr, Node *rightv = nullptr) {
        value = val;
        left = leftv;
        right = rightv;
    }
};

class Tree {
    Node *root = nullptr;
    int node_count = 0;
    int h(Node *root) {
        return root == nullptr ? -1 : root->height;
    }
    int get_balance(Node *root) {
        if (root == nullptr) {
            return 0;
        }
        return h(root->left) - h(root->right);
    }

    void update(Node *root) {
        if (root == nullptr) {
            return;
        }
        root->height = max(h(root->left), h(root->right)) + 1;
        root->size = get_size(root->left) + get_size(root->right) + 1;
    }

    Node *right_rotate(Node *root) {
        Node *left = root->left;
        Node *left_right = left->right;
        left->right = root;
        root->left = left_right;
        update(root);
        update(left);
        return left;
    }

    Node *left_rotate(Node *root) {
        Node *right = root->right;
        Node *right_left = right->left;
        right->left = root;
        root->right = right_left;
        update(root);
        update(right);
        return right;
    }
    Node *insert_help(Node *root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->value) {
            root->left = insert_help(root->left, val);
        } else {
            root->right = insert_help(root->right, val);
        }

        update(root);
        int balance_factor = get_balance(root);

        if (balance_factor > 1) {
            if (val < root->left->value) {
                return right_rotate(root);
            } else {
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
        }

        if (balance_factor < -1) {
            if (val >= root->right->value) {
                return left_rotate(root);
            } else {
                root->right = right_rotate(root->right);
                return left_rotate(root);
            }
        }

        return root;
    }

    int get_size(Node *root) {
        return root == nullptr ? 0 : root->size;
    }

    int get_sorted_pos_help(Node *root, int val) {
        if (root->value == val) {
            return get_size(root->left);
        } else if (val < root->value) {
            return get_sorted_pos_help(root->left, val);
        } else {
            return get_sorted_pos_help(root->right, val) + get_size(root->left) + 1;
        }
    }

    int find_help(Node *root, int val) {
        if (root == nullptr) return -1;
        if (val < root->value) {
            return find_help(root->left, val);
        } else if (root->value == val) {
            return root->value;
        } else {
            return find_help(root->right, val);
        }
    }

   public:
    int find(int val) {
        return find_help(root, val);
    }

    int get_sorted_pos(int val) {
        if (find(val) == -1) {
            return -1;
        }
        return get_sorted_pos_help(root, val);
    }

    void insert(int val) {
        root = insert_help(root, val);
        node_count++;
    }

    int size() {
        return node_count;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Tree tree;
    int tc, q, x;
    cin >> tc;
    while (tc--) {
        cin >> q >> x;
        if (q == 1) {
            tree.insert(x);
        } else {
            int pos = tree.get_sorted_pos(x);
            if (pos == -1) {
                cout << "Data tidak ada" << '\n';
            } else {
                cout << pos + 1 << '\n';
            }
        }
    }

    return 0;
}