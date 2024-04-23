#include <iostream>
#include <cmath>
#include "List.h"

using namespace std;

void Assert(bool expr, const string& msg) {
    if (!expr) {
        throw runtime_error(msg);
    }
}

template <typename E>
class ArrayList: public List<E> {
private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

    void increaseCapacity() {
        int newCapacity = floor(maxSize * 1.5);
        int oldCurr = curr;
        E *newListArray = new E[newCapacity];

        for (this->moveToStart(); this->currPos() < this->length(); this->next()) {
            newListArray[curr] = getValue();
        }

        delete[] listArray;

        maxSize = newCapacity;
        curr = oldCurr;
        listArray = newListArray;
    }
public:
    explicit ArrayList(int size=8) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    ~ArrayList() override { delete[] listArray; };


    void clear() override {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    void insert(const E& it) override {
        if (listSize > maxSize) {
            increaseCapacity();
        }
        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1]; // shifting elements up
        }
        listArray[curr] = it;
        listSize++;
    }

    void append(const E& it) override{
        if (listSize > maxSize) {
            increaseCapacity();
        }
        listArray[listSize++] = it;
    }

    // Remove and return the current element
    E remove() override{
        Assert((curr >= 0) && (curr < listSize), "NO element");
        E it = listArray[curr];
        for (int i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return it;
    }

    void moveToStart() override{
        curr = 0;
    }

    void moveToEnd() override{
        curr = listSize;
    }

    void prev() override{
        if (curr != 0) {
            curr--;
        }
    }

    void next() override{
        if(curr < listSize) {
            curr++;
        }
    }

    int length() const override{ return listSize; }
    int currPos() const override{ return curr; }

    void moveToPos(int pos) override{
        Assert((pos >= 0) && (pos <= listSize), "Position out of range");
        curr = pos;
    }

    const E& getValue() const override{
        Assert(( curr >= 0 ) && (curr <= listSize), "No current element");
        return listArray[curr];
    }


};


int main() {
    auto *list = new ArrayList<int>(1);

    list->insert(1);
    list->insert(2);
    list->insert(3);

    delete list;
    return 0;
}
