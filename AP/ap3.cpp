#include <iostream>
#include <cmath>
#include <string.h>
#include <map>
#include "List.h"

using namespace std;

template <typename E>
class ArrayList : public List<E>
{
private:
    int maxSize;
    int curr;
    int listSize;
    E *listArray;

public:
    explicit ArrayList(int size = 8)
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    };

    ~ArrayList() override { delete[] listArray; }

    void increaseCapacity()
    {
        int oldPos = curr;
        int newSize = ceil(maxSize * 1.5);
        E *newList = new E[newSize];

        for (moveToStart(); currPos() < length(); next())
        {
            newList[curr] = getValue();
        }

        delete[] listArray;
        maxSize = newSize;
        listArray = newList;
        curr = oldPos;
    }

    void increaseCapIfNeeded()
    {
        if (listSize >= maxSize)
        {
            increaseCapacity();
        }
    }

    void clear() override
    {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    void insert(const E &item) override
    {
        increaseCapIfNeeded();

        for (int i = listSize; i > curr; i--)
        {
            listArray[i] = listArray[i - 1];
        }
        listArray[curr] = item;
        listSize++;
    }

    void append(const E &item) override
    {
        increaseCapIfNeeded();

        listArray[listSize++] = item;
    }

    E remove() override
    {
        E current = listArray[curr];
        for (int i = curr; i < listSize - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return current;
    }

    void moveToStart() override
    {
        curr = 0;
    }

    void moveToEnd() override
    {
        curr = listSize;
    }

    int count(const E &item)
    {
        int oldCurr = curr;
        int count = 0;
        for (moveToStart(); currPos() < length(); next())
        {
            if (getValue() == item)
            {
                count++;
            }
        }
        curr = oldCurr;
        return count;
    }

    void moveToPos(int pos) override
    {
        if (pos >= 0 && pos <= listSize)
        {
            curr = pos;
        }
    }

    void prev() override
    {
        if (curr != 0)
        {
            curr--;
        }
    }

    void next() override
    {
        if (curr < listSize)
        {
            curr++;
        }
    }

    int length() const override
    {
        return listSize;
    }

    int currPos() const override
    {
        return curr;
    }

    const E &getValue() const override
    {
        return listArray[curr];
    }
};

int main()
{
    auto *list = new ArrayList<int>();

    int c;
    cin >> c;
    int op_number;
    cin >> op_number;

    for (int k = 0; k < c; k++)
    {
        cout << "Caso " << k + 1 << ":" << '\n';
        for (int i = 0; i < op_number; i++)
        {
            string s;
            cin >> s;
            if (s == "next")
            {
                list->next();
            }
            else if (s == "prev")
            {
                list->prev();
            }
            else if (s == "remove")
            {
                list->remove();
            }
            else if (s == "insert")
            {
                int n;
                cin >> n;
                list->insert(n);
            }
            else if (s == "count")
            {
                int n;
                cin >> n;
                int count = list->count(n);
                cout << count << '\n';
            }
        }
    }

    return 0;
}