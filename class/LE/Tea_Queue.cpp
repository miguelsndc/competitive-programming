#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename E>
class Link {
public:
    E element;
    Link *next;

    Link(const E &elemval, Link *nextval = NULL) {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL) {
        next = nextval;
    }
};

template <typename E>
class Queue {
private:
    Link<E> *front;
    Link<E> *rear;
    int size = 0;

public:
    Queue() {
        front = rear = new Link<E>();
        size = 0;
    }

    void clear() {
        while (front->next != NULL) {
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(E item) {
        rear->next = new Link<E>(item, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue() {
        E item = front->next->element;
        Link<E> *temp = front->next;
        front->next = temp->next;
        if (rear == temp)
            rear = front;
        delete temp;
        size--;
        return item;
    }

    E frontValue() {
        if (size > 0) {
            return front->next->element;
        }
    }

    int length() const { return size; }
};

void solve(int n) {
    auto *tea_queue = new Queue<pair<int, int>>();
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        tea_queue->enqueue(make_pair(l, r));
    }

    int elapsed = 1;
    while (tea_queue->length() > 0) {
        auto front = tea_queue->frontValue();
        if (front.first <= elapsed && elapsed <= front.second) {
            cout << elapsed << ' ';
            tea_queue->dequeue();
            elapsed++;
        } else if (front.first > elapsed) {
            elapsed++;
        } else if (front.second < elapsed) {
            cout << 0 << ' ';
            tea_queue->dequeue();
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cases = 1;
    cin >> cases;
    while (cases--) {
        cin >> n;
        solve(n);
    }

    return 0;
}