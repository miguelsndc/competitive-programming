#include <math.h>

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

template <typename K, typename V>
class HashTable {
   private:
    struct Node {
        K key;
        V value;
        Node(K k, V v) : key(k), value(v) {}
    };

    int cnt = 0;
    size_t capacity;
    vector<Node *> table;

    int hash(int key, int mod) {
        int temp = (int)floor((((double)key) / ((double)mod)));
        return (key - (mod * temp));
    }

   public:
    vector<int> random_vec;

    int probing(K key, int i) {
        return random_vec[i - 1];
    }

    HashTable(size_t size = 16) {
        capacity = size;
        table.resize(capacity, nullptr);
        random_vec.resize(size - 1);
    };

    void insert(K key, V value) {
        if (cnt >= capacity || find(key).first != -1) return;

        int pos = hash(key, capacity);
        if (table[pos] != nullptr) {
            int i = 0;
            do {
                i++;
                pos = (pos + probing(key, i)) % capacity;
            } while (table[pos] != nullptr);
        }

        table[pos] = new Node(key, value);
        cnt++;
    }

    pi find(K key) {
        int pos = hash(key, capacity);

        int i = 0;
        do {
            i++;
            auto entry = table[pos];
            if (entry != nullptr && entry->key == key) {
                return make_pair(pos, entry->value);
            }
            pos = (pos + probing(key, i)) % capacity;
        } while (table[pos] != nullptr && i <= cnt);
        return make_pair(-1, -1);
    }
};

int main() {
    int m;
    cin >> m;
    auto table = new HashTable<int, int>(m);
    for (int i = 0; i < m - 1; i++) {
        int k;
        cin >> k;
        table->random_vec[i] = k;
    }

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        string op;
        cin >> op;

        if (op == "0") break;

        if (op == "add") {
            int key, value;
            cin >> key >> value;
            table->insert(key, value);
        } else {
            int key;
            cin >> key;
            pi p = table->find(key);
            if (p.first == -1) {
                cout << -1 << '\n';
            } else {
                cout << p.first << ' ' << p.second << '\n';
            }
        }
    }

    return 0;
}