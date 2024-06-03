#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class HashTable {
   private:
    struct Node {
        K key;
        V value;
        Node(K k, V v) : key(k), value(v) {}
    };

    size_t capacity;
    int cnt = 0;

    Node *deleted_sentinel;

    vector<Node *> table;

    int hash(K key) {
        return key % this->capacity;
    }

    int probing(K key, int i) {
        return i;
    }

   public:
    HashTable(size_t size = 16) {
        capacity = size;
        table.resize(capacity, nullptr);
    };

    void insert(K key, V value) {
        if (size() >= capacity) return;
        int pos = hash(key);

        if (table[pos] != nullptr && table[pos] != deleted_sentinel) {
            int i = 0;
            do {
                i++;
                pos = (pos + probing(key, i)) % capacity;
            } while (table[pos] != nullptr && table[pos] != deleted_sentinel);
        }

        table[pos] = new Node(key, value);
        cnt++;
    }

    V find(K key) {
        int pos = hash(key);
        int i = 0;
        do {
            i++;
            auto entry = table[pos];
            if (entry->key == key) {
                return entry->value;
            }
            pos = (pos + probing(key, i)) % capacity;
        } while (table[pos] != nullptr && table[pos] != deleted_sentinel);
        return V();
    }

    V remove(K key) {
        int pos = hash(key);
        int i = 0;
        do {
            i++;
            Node *entry = table[pos];
            if (entry->key == key) {
                V val = entry->value;
                table[pos] = deleted_sentinel;
                return val;
            }
            pos = (pos + probing(key, i)) % capacity;
        } while (table[pos] != nullptr && table[pos] != deleted_sentinel);
        return V();
    }

    int size() {
        return cnt;
    }

    float load_factor() {
        return size() * 1.0 / capacity;
    }
};

int main() {
    HashTable<int, int> table;
    table.insert(10, 11);
    table.find(10);
    table.remove(10);

    return 0;
}