#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <typename K>
class HashTable {
   private:
    size_t capacity = 101;
    string deleted_sentinel = "@d@dsomdos100e0ka0fdamce@l@e@t@e@d@;____09jao91";
    vector<string> table;

    int hash(string key) {
        int sum = 0;
        int i = 1;
        for (char c : key) {
            sum += c * i++;
        }
        return (19 * sum) % capacity;
    }

   public:
    HashTable() {
        table.resize(capacity, "");
    };

    int cnt = 0;
    void insert(K key) {
        if (cnt >= capacity || find(key) != -1) return;
        int pos, start = hash(key);
        for (int i = 0; i < 20; i++) {
            pos = (start + (i * i) + (23 * i)) % capacity;
            if (table[pos] == "" || table[pos] == deleted_sentinel) {
                table[pos] = key;
                cnt++;
                return;
            }
        }
    }

    int find(K key) {
        if (cnt == 0) return -1;
        int pos, start = hash(key);
        for (int i = 0; i < 20; i++) {
            pos = (start + (i * i) + (23 * i)) % capacity;
            if (table[pos] != "" && table[pos] != deleted_sentinel && table[pos] == key) {
                return pos;
            }
        }
        return -1;
    }

    void remove(K key) {
        if (cnt == 0 || find(key) == -1) return;
        int pos, start = hash(key);
        for (int i = 0; i < 20; i++) {
            pos = (start + (i * i) + (23 * i)) % capacity;
            if (table[pos] != "" && table[pos] != deleted_sentinel && table[pos] == key) {
                table[pos] = deleted_sentinel;
                cnt--;
                return;
            }
        }
    }

    void write() {
        cout << cnt << '\n';
        for (int i = 0; i < capacity; i++) {
            if (table[i] != "" && table[i] != deleted_sentinel) {
                cout << i << ':' << table[i] << '\n';
            }
        }
    }
};

int main() {
    int t, c;
    cin >> t;

    for (int j = 0; j < t; j++) {
        cin >> c;
        HashTable<string> tb;
        for (int i = 0; i < c; i++) {
            string line;
            cin >> line;
            int colon = line.find(':');
            string command = line.substr(0, colon);
            string arg = line.substr(colon + 1);

            if (command == "ADD") {
                tb.insert(arg);
            } else if (command == "DEL") {
                tb.remove(arg);
            }
        }
        if (tb.cnt > 0)
            tb.write();
    }
    return 0;
}