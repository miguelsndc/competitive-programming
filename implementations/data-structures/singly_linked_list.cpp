#include <iostream>
#include "List.h"

using namespace std;

void Assert(bool expr, string msg)
{
    if (!expr)
    {
        throw runtime_error(msg);
    }
}

template <typename E>
class Link
{
private:
    static Link<E> *freelist;

public:
    E element;
    Link *next;

    Link(const E &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }

    void *operator new(size_t)
    {
        if (freelist == NULL)
            return ::new Link;
        Link<E> *temp = freelist;
        freelist = freelist->next;
        return temp;
    }

    void operator delete(void *ptr)
    {
        ((Link<E> *)ptr)->next = freelist;
        freelist = (Link<E> *)ptr;
    }
};

template <typename E>
class LinkedList : public List<E>
{
private:
    Link<E> *head;
    Link<E> *tail;
    Link<E> *curr;
    int cnt;

    void init()
    {
        head = tail = curr = new Link<E>;
        cnt = 0
    }

    void remove_all()
    {
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LinkedList()
    {
        init();
    }
    ~LinkedList()
    {
        remove_all();
    }

    void print() const;

    void clear()
    {
        remove_all();
        init();
    }

    void insert(const E &item) override
    {
        curr->next = new Link<E>(item, curr->next);
        if (tail == curr)
        {
            tail = curr->next;
        }

        cnt++;
    }

    void append(const E &item) override
    {
        tail = tail->next = new Link<E>(item, NULL);
        cnt++;
    }

    E remove()
    {
        E item = curr->next->element;
        Link<E> *ltemp = curr->next;
        if (tail == curr->next)
            tail = curr;

        curr->next = curr->next->next;
        delete ltemp;
        cnt--;
        return item;
    }

    void moveToStart()
    {
        curr = head;
    }

    void moveToEnd()
    {
        curr = tail;
    }

    void prev()
    {
        if (curr == head)
            return;

        Link<E> *temp = head;
        while (temp->next != curr)
        {
            temp = temp->next;
        }
        curr = temp;
    }

    void next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }

    int length() const
    {
        return cnt;
    }

    int currPos()
    {
        Link<E> *temp = head;
        int i = 0;
        for (i = 0; curr != temp; i++)
        {
            temp = temp->next;
        }
        return i;
    }

    void moveToPos(int pos)
    {
        Assert((pos >= 0 && pos <= cnt), "Position out of range");
        curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
    }

    const E &getValue()
    {
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};