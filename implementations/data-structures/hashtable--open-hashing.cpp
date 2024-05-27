#include <iostream>
#include <vector>
using namespace std;

template <typename K, typename E>
class Dictionary
{
    virtual void clear() = 0;
    virtual void insert(K key, E value) = 0;
    virtual E remove(K key) = 0;
    // virtual E removeAny(K key) = 0;
    virtual E find(K key) = 0;
    virtual int length() = 0;
    virtual int hash(K key) = 0;
};

template <typename K, typename E>
class HashTable : public Dictionary<K, E>
{

private:
    int size = 10;
    int cnt = 0;

    typedef vector<pair<K, E>> list;
    typedef list *list_ptr;
    list_ptr table[10];

    int hash(K key)
    {
        return key % size;
    }

public:
    HashTable(int p_size = 10)
    {
        size = p_size;
    }

    void insert(K key, E value)
    {
        int pos = hash(key);
        list *l = table->at(pos);
        l->push_back(make_pair(key, value));
    }
    E find(K key)
    {
        int pos = hash(key);
        list *l = table[pos];
        for (int i = 0; i < l->size(); i++)
        {
            if (l->at(i).first == key)
            {
                return l->at(i).second;
            }
        }
    }

    int main()
    {
        return 0;
    }
};