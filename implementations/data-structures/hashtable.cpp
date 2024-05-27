#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K, typename E>
class HashTable
{
private:
    int size = 10;
    int cnt = 0;
    typedef vector<pair<K, E>> list;
    list *table[10];
    int hash(K key) { return key % size; };

public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
            table[i] = new vector<pair<K, E>>();
    }

    void insert(K key, E value)
    {
        if (find(key) == nullptr)
        {
            int pos = hash(key);
            list *l = table[pos];
            l->push_back(make_pair(key, value));
        }
    }

    E *find(K key)
    {
        int pos = hash(key);
        list *l = table[pos];
        for (pair<K, E> &cell : (*l))
        {
            if (cell.first == key)
                return &cell.second;
        }
        return nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    HashTable<int, int> *tb = new HashTable<int, int>();

    tb->insert(2, 3);
    int *val = tb->find(2);
    cout << *val;
    return 0;
}