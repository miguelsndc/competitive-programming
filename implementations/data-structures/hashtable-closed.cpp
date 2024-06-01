#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template <typename K, typename V>
class Entry {
   public:
    K key;
    V value;
    bool deleted = false;
    bool empty = true;

    Entry(K keyval, V valval) : key(keyval), value(valval) {
        empty = false;
    }
    Entry() {
        key = K();
        value = V();
        empty = true;
    }

    void mark_deleted() {
        deleted = true;
        empty = false;
        key = K();
        value = V();
    }
};
template <typename K, typename V>
class HashTable {
   private:
    size_t capacity;
    vector<Entry<K, V>*> table;
    int cnt = 0;
    int hash(K key) { return key % this->capacity; };

    int probing(K key, int i) {
        return i;
    }

   public:
    HashTable(size_t size = 16) {
        capacity = size;
        table.resize(capacity);
        for (int i = 0; i < capacity; i++) {
            table[i] = new Entry<K, V>();
        }
    }

    void insert(K key, V value) {
        if (size() >= capacity) return;
        int pos = hash(key);

        if (!table[pos]->empty && !table[pos]->deleted) {
            int i = 0;
            do {
                i++;
                pos = (pos + probing(key, i)) % capacity;
            } while (!table[pos]->empty && !table[pos]->deleted);
        }
        table[pos] = new Entry<K, V>(key, value);
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
        } while (!table[pos]->empty && !table[pos]->deleted);
        return V();
    }

    V remove(K key) {
        int pos = hash(key);
        int i = 0;
        do {
            i++;
            auto entry = table[pos];
            if (entry->key == key) {
                V val = entry->value;
                entry->mark_deleted();
                return val;
            }
        } while (!table[pos]->empty && !table[pos]->deleted);
        return V();
    }

    int size() {
        return cnt;
    }

    float monitor_load_factor() {
        return size() * 1.0 / capacity;
    }

    void increase_capacity() {
    }
};

int main() {
    HashTable<int, int> table;

    table.insert(16, 20);
    table.insert(32, 12);

    table.find(32);
    table.remove(32);

    return 0;
}