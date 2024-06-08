#include <string.h>

#include <iostream>

using namespace std;
// Height of empty subtree is -1.

template <typename K, typename E>
struct Node {
    K key;
    E element;
    Node* left;
    Node* right;
    int height;
    Node(K keyval = K(), E elval = V(), Node* leftchild = nullptr, Node* rightchild = nullptr) {
        key = keyval;
        element = elval;
        left = leftchild;
        right = rightchild;
        height = 0;
    }
};

template <typename K, typename E>
struct AVLTree {
    typedef Node<K, E>* AVLNode;

    AVLNode root = nullptr;
    int node_count = 0;

    int h(AVLNode root) {
        if (root == nullptr) return -1;
        return root->height;
    }
    int get_balance(AVLNode root) {
        if (root == nullptr) return 0;
        return h(root->left) - h(root->right);
    }

    AVLNode right_rotate(AVLNode root) {
        AVLNode left = root->left;
        AVLNode left_right = left->right;
        left->right = root;
        root->left = left_right;
        root->height = max(h(root->left), h(root->right)) + 1;
        left->height = max(h(left->left), h(left->right)) + 1;
        return left;
    }

    AVLNode left_rotate(AVLNode root) {
        AVLNode right = root->right;
        AVLNode right_left = right->left;
        right->left = root;
        root->right = right_left;
        root->height = max(h(root->left), h(root->right)) + 1;
        right->height = max(h(right->left), h(right->right)) + 1;
        return right;
    }

    AVLNode insert_help(AVLNode root, K key, E element) {
        if (root == nullptr) {
            return new Node<K, E>(key, element);
        }
        if (key < root->key) {
            root->left = insert_help(root->left, key, element);
        } else {
            root->right = insert_help(root->right, key, element);
        }

        root->height = 1 + max(h(root->left), h(root->right));
        int balance = get_balance(root);

        // Pesando pra esquerda
        if (balance > 1) {
            if (key < root->left->key) {
                return right_rotate(root);
            } else {
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
        }
        // Pesando pra direita
        if (balance < -1) {
            if (key >= root->right->key) {
                return left_rotate(root);
            } else {
                root->right = right_rotate(root->right);
                return left_rotate(root);
            }
        }

        return root;
    }

    E find_help(AVLNode root, K key) {
        if (root == nullptr) return NULL;
        if (key < root->key) {
            return find_help(root->left, key);
        } else if (key == root->key) {
            return root->element;
        } else {
            return find_help(root->right, key);
        }
    }

    Node<K, E>* get_min(Node<K, E>* root) {
        if (root->left == nullptr) return root;
        return get_min(root->left);
    }

    Node<K, E>* delete_min(Node<K, E>* root) {
        if (root->left == nullptr) return root->right;
        root->left = delete_min(root->left);
        return root;
    }

    void in_order_help(Node<K, E>* root, void (*visitor)(E)) {
        if (root == nullptr) return;
        in_order_help(root->left, visitor);
        visitor(root->element);
        in_order_help(root->right, visitor);
    }

    void pre_order_help(Node<K, E>* root, void (*visitor)(E)) {
        if (root == nullptr) return;
        visitor(root->element);
        pre_order_help(root->left, visitor);
        pre_order_help(root->right, visitor);
    }

    void post_order_help(Node<K, E>* root, void (*visitor)(E)) {
        if (root == nullptr) return;
        post_order_help(root->left, visitor);
        post_order_help(root->right, visitor);
        visitor(root->element);
    }

    void clear(Node<K, E>* root) {
        if (root == nullptr) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

   public:
    ~AVLTree() {
        clear(root);
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

    void insert(K key, E element) {
        root = insert_help(root, key, element);
        node_count++;
    }

    E find(K key) {
        return find_help(root, key);
    }
};

int main() {
    AVLTree<int, int> tree;

    tree.insert(10, 11);
    tree.insert(20, 11);
    tree.insert(30, 11);

    return 0;
}