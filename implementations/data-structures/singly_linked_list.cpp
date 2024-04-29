#include <iostream>
#include "List.h"

template <typename E>
class Link
{
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
};