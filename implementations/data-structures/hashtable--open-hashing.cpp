#include <iostream>
#include <bits/stdc++.h>

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

// OPEN HASHING
template <typename K, typename E>
class Entry
{
public:
    K key;
    E value;
    Entry(K k, E v = NULL)
    {
        key = k;
        value = v;
    }
};

template <typename K, typename E>
class HashTable : public Dictionary<K, E>
{
private:
    int size = 16;
    int cnt = 0;
    list<Entry<K, E>> table[];

    void create_dict()
    {
        table = new list<Entry<K, E>>[size];
        for (int i = 0; i < size - 1; i++)
            table[i] = new list<Entry<K, E>>();
    }

public:
    HashTable(int p_size)
    {
        size = p_size;
        create_dict();
    }
    HashTable()
    {
        create_dict();
    }

    int hash(int key)
    {
        return key % size;
    }

    int hash(string key)
    {
        int s = key.length();
        int sum = 0;
        for (char ch : key)
            sum += (int)ch;
        return abs(sum) % size;
    }

    void insert(K key, E value)
    {
        if (find(key) == NULL)
        {
            int pos = hash(key);
            list<Entry<K, E>> chain = table[pos];
            Entry<K, E> entry = new Entry<K, E>(key, value);
            chain.push_back(entry);
            cnt++;
        }
    }
    E find(K key)
    {
        int pos = hash(key);
        list<Entry<K, E>> chain = table[pos];
        for (Entry<K, E> item : chain)
        {
            if (key == item.key)
                return item.value;
        }
        return NULL;
    }

    E remove(K key)
    {
        int pos = hash(key);
        list<Entry<K, E>> chain = table[pos];
        Entry<K, E> val_to_be_removed = NULL;
        for (Entry<K, E> item : chain)
        {
            if (key == item.key)
                val_to_be_removed = item;
        }
        if (val_to_be_removed != NULL)
        {
            chain.remove(val_to_be_removed);
            cnt--;
        }

        return val_to_be_removed;
    }

    int length() { return cnt; }

    void clear()
    {
        for (int i = 0; i < size; i++)
        {
            for (Entry<K, E> item : table[i])
            {
                delete item;
            }
            delete table[i];
        }
        create_dict();
    }
};

int main()
{
    HashTable<string, int> mp;

    return 0;
}