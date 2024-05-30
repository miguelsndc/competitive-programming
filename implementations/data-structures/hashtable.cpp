#include <iostream>
#include <list>
#include <vector>

using namespace std;
using ll = long long;

template <typename K, typename V>
class HashTable {
   private:
    struct Node {
        K key;
        V value;
    };

    vector<list<Node>> table;
    size_t capacity;
    int cnt = 0;
    // se eu aumento a capacity depois de declarar isso aqui ele deve pegar a antiga, acho q isso resolve
    int hash(K key) { return key % this->capacity; };

   public:
    HashTable(size_t size) : capacity(size) {
        table.resize(size);
    }

    int size() {
        return cnt;
    }

    float monitor_load_factor() {
        return size() * 1.0 / capacity;
    }

    void increase_capacity() {
        float threshold = 0.75;
        float lf = monitor_load_factor();
        if (lf > threshold) {
            capacity = capacity * 2;
            vector<list<Node>> new_table;
            // como mover chaves pra nova tabela sem passar por todas posições vazias ?
        }
    }

    void insert(K key, V value) {
        int pos = hash(key);
        // ---- SUBSCRIÇÃO DA CHAVE -----
        // for (Node &node : table[pos])
        // {
        //     if (node.key == key)
        //     {
        //         node.value = value;
        //         return;
        //     }
        // }
        if (find(key) == V())  // ???{
        {
            table[pos].push_back({key, value});
            cnt++;
        }
    }

    V find(K key) {
        int pos = hash(key);
        list<Node> &addr_list = table[pos];
        for (Node &node : addr_list) {
            if (node.key == key) {
                return node.value;
            }
        }
        return V();  // o que diabos eu retorno aqui
    }

    V remove(K key) {
        int pos = hash(key);
        list<Node> &addr_list = table[pos];
        typename list<Node>::iterator it;
        for (it = addr_list.begin(); it != addr_list.end(); ++it) {
            if (it->key == key) {
                V val = it->value;  // como garantir q isso seja uma copia e nao um ponteiro pra algo
                addr_list.erase(it);
                cnt--;
                return val;
            }
        }
        return V();
    }
};

int main() {
    auto tb = new HashTable<int, int>(10);

    tb->insert(10, 23);
    cout << tb->find(10) << '\n';
    cout << tb->monitor_load_factor() << '\n';
    cout << tb->remove(10) << "\n";
    cout << tb->monitor_load_factor() << "\n";

    return 0;
}