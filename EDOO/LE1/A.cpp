#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

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
    void push(E item) {
        rear->next = new Link<E>(item, NULL);
        rear = rear->next;
        size++;
    }
    E pop() {
        E item = front->next->element;
        Link<E> *temp = front->next;
        front->next = temp->next;
        if (rear == temp)
            rear = front;
        delete temp;
        size--;
        return item;
    }

    E front_val() {
        if (size > 0) {
            return front->next->element;
        }
    }
    int length() const { return size; }
    int empty() const { return size == 0; }
};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        ll cap, m; cin >> cap >> m; cap = cap * 100;
        Queue<ll> lq, rq;
        loop(i, 0, m) {
            int length; cin >> length;
            string dir; cin >> dir;
            if (dir == "left") {
                lq.push(length);
            } else {
                rq.push(length);
            }
        }
        bool is_left = true;
        ll turns = 0;
        ll n = 0;
        while(!lq.empty() || !rq.empty()) {
            if (is_left) {
                while(!lq.empty() && (n + lq.front_val()) <= cap) {
                    n += lq.front_val(); lq.pop();
                }
                turns++; n = 0;
            } else {
                while(!rq.empty() && (n + rq.front_val()) <= cap) {
                    n += rq.front_val(); rq.pop();
                }
                turns++; n = 0;
            }
            is_left = !is_left;
        }
        cout << turns << '\n';
    }
}