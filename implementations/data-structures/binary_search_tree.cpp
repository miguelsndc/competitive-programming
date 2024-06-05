#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

void Assert(bool expr, string msg) {
    if (!expr) {
        throw runtime_error(msg);
    }
}

template <typename K, typename E>
struct Node {
    K key;
    E element;
    Node *left;
    Node *right;
    Node(K keyval, E elementval, Node<K, E> *leftp = nullptr, Node<K, E> *rightp = nullptr) {
        key = keyval;
        element = elementval;
        left = leftp;
        right = rightp;
    }
};

template <typename K, typename E>
struct BinarySearchTree {
   private:
    Node<K, E> *root = nullptr;
    int node_count = 0;

    E find_help(Node<K, E> *root, K key) {
        if (root == nullptr) return NULL;
        if (root->key > key) {
            return find_help(root->left, key);
        } else if (root->key == key) {
            return root->element;
        } else {
            return find_help(root->right, key);
        }
    }
    Node<K, E> *insert_help(Node<K, E> *root, K key, E el) {
        if (root == nullptr) {
            return new Node<K, E>(key, el);
        }
        if (root->key > key) {
            root->left = insert_help(root->left, key, el);
        } else {
            root->right = insert_help(root->right, key, el);
        }

        return root;
    }

    Node<K, E> *get_min(Node<K, E> *root) {
        if (root->left == nullptr) return root;
        return get_min(root->left);
    }

    Node<K, E> *delete_min(Node<K, E> *root) {
        if (root->left == nullptr) return root->right;
        root->left = delete_min(root->left);
        return root;
    }

    Node<K, E> *remove_help(Node<K, E> *root, K key) {
        if (root == nullptr) return NULL;

        if (root->key > key) {
            root->left = remove_help(root->left, key);
        } else if (root->key < key) {
            root->right = remove_help(root->right, key);
        } else {
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                Node<K, E> *temp = get_min(root->right);
                root->key = temp->key;
                root->element = temp->element;
                root->right = delete_min(root->right);
            }
        }
        return root;
    }
    void in_order_help(Node<K, E> *root, void (*visitor)(E)) {
        if (root == nullptr) return;
        in_order_help(root->left, visitor);
        visitor(root->element);
        in_order_help(root->right, visitor);
    }

    void pre_order_help(Node<K, E> *root, void (*visitor)(E)) {
        if (root == nullptr) return;
        visitor(root->element);
        pre_order_help(root->left, visitor);
        pre_order_help(root->right, visitor);
    }

    void post_order_help(Node<K, E> *root, void (*visitor)(E)) {
        if (root == nullptr) return;
        post_order_help(root->left, visitor);
        post_order_help(root->right, visitor);
        visitor(root->element);
    }

    Node<K, E> *update_help(Node<K, E> *root, K key, E element) {
        if (root == nullptr) return NULL;
        if (root->key > key) {
            root->left = update_help(root->left, key, element);
        } else if (root->key < key) {
            root->right = update_help(root->right, key, element);
        } else {
            root->element = element;
        }
        return root;
    }

    void clear(Node<K, E> *root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

   public:
    ~BinarySearchTree() {
        clear(root);
    }

    void insert(K key, E el) {
        root = insert_help(root, key, el);
        node_count++;
    }

    void in_order(void (*visitor)(E)) {
        return in_order_help(root, visitor);
    }

    void pre_order(void (*visitor)(E)) {
        return pre_order_help(root, visitor);
    }

    void post_order(void (*visitor)(E)) {
        return post_order_help(root, visitor);
    }

    E find(K key) {
        return find_help(root, key);
    }

    E remove(K key) {
        E temp = find_help(root, key);
        if (temp != NULL) {
            root = remove_help(root, key);
            node_count--;
        }
        return temp;
    }

    void update(K key, E value) {
        root = update_help(root, key, value);
    }

    int size() {
        return node_count;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    BinarySearchTree<int, int> bst;
    for (int i = 0; i < 50; i++) {
        bst.insert(i, i * i);
    }

    bst.in_order([](int a) {
        cout << a << '\n';
    });
}