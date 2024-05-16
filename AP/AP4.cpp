#include <iostream>

template <typename E>
class Link
{
public:
    E element;
    Link *next;

    Link(const E data, Link *nextval = NULL)
    {
        next = nextval;
        element = data;
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
    int cnt = 0;

    void init()
    {
        head = tail = curr = new Link<E>;
        cnt = 0;
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

    void insert(const E item)
    {
        // o-c-o-o
        curr->next = new Link<E>(item, curr->next);
        if (tail == curr)
            tail = curr->next;
        cnt++;
    }

    E remove()
    {
        if (curr->next == NULL)
        {
            return NULL;
        }
        E item = curr->next->element;
        Link<E> *temp = curr->next;
        if (tail == curr->next)
            tail = curr;
        curr->next = curr->next->next;
        delete temp;
        cnt--;
        return item;
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

    void next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }

    int length()
    {
        return cnt;
    }

    int count(int target)
    {
        Link<E> *temp = head;
        int c = 0;
        while (temp != tail)
        {
            if (temp->next->element == target)
            {
                c++;
            }
            temp = temp->next;
        }

        return c;
    }
};

int main()
{
    int c;
    std::cin >> c;
    for (int i = 1; i <= c; i++)
    {
        int n;
        std::cin >> n;
        auto *list = new LinkedList<int>();

        std::cout << "Caso " << i << ':' << '\n';

        for (int j = 0; j < n; j++)
        {
            std::string command;
            std::cin >> command;

            if (command == "insert")
            {
                int arg;
                std::cin >> arg;
                list->insert(arg);
            }
            else if (command == "next")
            {
                list->next();
            }
            else if (command == "remove")
            {
                list->remove();
            }
            else if (command == "count")
            {
                int arg;
                std::cin >> arg;
                int count = list->count(arg);
                std::cout << count << '\n';
            }
        }
    }
}