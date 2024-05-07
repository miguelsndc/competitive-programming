#include <iostream>

template <typename E>
class Link
{
public:
    E *element;
    Link *next;

    Link(E &item, Link *nextval = NULL)
    {
        element = item;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};

template <typename E>
class LinkedList
{
private:
    Link<E> *head;
    Link<E> *tail;
    Link<E> *curr;
    int cnt;

    void init()
    {
        head = tail = curr = new Link<E>;
        cnt = 0;
    }

    void destroy()
    {
        while (head != NULL)
        {
            curr = head;
            head = curr.next;
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
        destroy();
    }

    clear()
    {
        destroy();
        init();
    }

    void insert(E &item)
    {
        curr->next = new Link<E>(item, curr->next);
        if (curr = tail)
        {
            tail = curr->next;
        }
        cnt++;
    }

    E remove()
    {
        if (curr->next == NULL)
            return NULL;
        E item = curr->next->element;
        Link<E> *temp = curr->next;
        if (tail == curr->next)
            tail = curr;
        curr->next = curr->next->next;
        cnt--;
        delete temp;
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

    void next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }

    void prev()
    {
        if (curr == head)
        {
            return;
        }

        Link<E> *temp = head;
        while (temp->next != curr)

        {
            temp = temp->next;
        }
        curr = temp;
    }

    void currPos()
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
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }

    int length()
    {
        return cnt;
    }

    E &getValue()
    {
        return curr->next->element;
    }
};

int main()
{
    return 0;
}