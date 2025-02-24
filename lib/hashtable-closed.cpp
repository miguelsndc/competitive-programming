#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Entry {
   public:
    K key;
    V value;
    bool deleted = false;

    Entry(K keyval, V valval) : key(keyval), value(valval) {
    }
    Entry() {
        key = NULL;
        value = NULL;
    }

    void mark_deleted() {
        deleted = true;
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
    // q eu saiba só strings e numeros sao hasheaveis
    int hash(size_t key) { return key % this->capacity; };
    int hash(string key) {
        int len = key.length() / 4;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            string sub = key.substr(i * 4, (i * 4) + 4);
            int mult = 1;
            for (int j = 0; j < 4; j++) {
                sum += sub[j] * mult;
                mult *= 256;
            }
        }
        string sub = key.substr(len * 4);
        int mult = 1;
        int s_len = sub.length();
        for (int j = 0; j < s_len; j++) {
            sum += sub[j] * mult;
            mult *= 256;
        }
        return abs(sum) % this->capacity;
    }

    // so pra ver se pega
    int probing(K key, int i) {
        return i;
    }

   public:
    HashTable(size_t size = 16) {
        capacity = size;
        table.resize(capacity);
        for (int i = 0; i < capacity; i++) {
            table[i] = nullptr;
        }
    }

    void insert(K key, V value) {
        if (size() >= capacity) return;  // TODO: increaseCapacity() -> rehashear tudo pra uma tabela maior
        int pos = hash(key);

        if (table[pos] != nullptr && !table[pos]->deleted) {
            int i = 0;
            do {
                i++;
                pos = (pos + probing(key, i)) % capacity;
            } while (table[pos] != nullptr && !table[pos]->deleted);
        }

        if (table[pos] != nullptr) {  // table[pos] é uma entry deletada
            table[pos]->key = key;
            table[pos]->value = value;
            table[pos]->deleted = false;
        } else {
            table[pos] = new Entry<K, V>(key, value);
        }
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
        } while (table[pos] != nullptr && !table[pos]->deleted);
        return V();  //
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
            pos = (pos + probing(key, i)) % capacity;
        } while (table[pos] != nullptr && !table[pos]->deleted);
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
    HashTable<string, int> table;
    table.insert("oi", 20);
    table.remove("oi");
    table.insert("oi", 320);

    return 0;
}