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
    int length() const { return size; }
};