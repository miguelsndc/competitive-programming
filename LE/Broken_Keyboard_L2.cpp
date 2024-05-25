#include <iostream>
using namespace std;

template <typename E>
class Link
{
public:
    E element;
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
public:
    Link<E> *head;
    Link<E> *tail;
    Link<E> *curr;
    int cnt;

    LinkedList()
    {
        head = tail = curr = new Link<E>();
        cnt = 0;
    }

    void insert(E &item)
    {
        curr->next = new Link<E>(item, curr->next);
        if (curr == tail)
        {
            tail = curr->next;
        }
        cnt++;
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
            curr = curr->next;
    }
};

void solve(string s)
{
    auto list = new LinkedList<char>();
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '[')
            list->moveToStart();
        else if (ch == ']')
            list->moveToEnd();
        else
        {
            list->insert(ch);
            list->next();
        }
    }
    for (list->moveToStart(); list->curr != list->tail; list->next())
        cout << list->curr->next->element;

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while (cin >> line)
        solve(line);

    return 0;
}