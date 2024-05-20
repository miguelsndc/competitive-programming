#include <iostream>

using namespace std;

template <typename E>
class Link {

public:
    E element;
    Link *next;

    Link(E &val, Link *nextval = NULL) {
        element = val;
        next = nextval;
    }
    Link(Link *nextval = NULL) {
        next = nextval;
    }
};

template <typename E>
class Queue {
public:
    Link<E> *front;
    Link<E> *rear;
    int size = 0;

    Queue() {
        front = rear = new Link<E>();
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

    int length() const { return size; }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string command;
    int args;
    int solved = 0;
    auto *bank_queue = new Queue<int>();
    while (cin >> command && command != "end") {
        if (command == "add") {
            cin >> args;
            bank_queue->enqueue(args);
        } else if (command == "solve" && bank_queue->length() > 0) {
            bank_queue->dequeue();
            solved++;
        } else if (command == "stats") {
            cout << solved << ' ' << bank_queue->length() << '\n';
        } else if (command == "print") {
            auto *temp = bank_queue->front;

            if (bank_queue->length() == 0)
                cout << 'x' << '\n';
            else {
                while (temp->next != bank_queue->rear) {
                    cout << temp->next->element << " ";
                    temp = temp->next;
                }
                cout << temp->next->element;
                cout << '\n';
            }
        }
    }
    return 0;
}