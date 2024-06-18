#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

using namespace std;

class Heap {
   private:
    vector<int>& heap;
    int max_size;
    int n;

    void sift(int pos) {
        int k = pos;
        int v = heap[k];
        int is_heap = false;
        while (!is_heap && left_child(k) <= n) {
            int j = left_child(k);
            if (j < n) {
                if (heap[j] > heap[j + 1]) {  // right child is greater
                    j = right_child(k);
                }
            }

            if (v <= heap[j]) {  // heap property ok
                is_heap = true;
            } else {
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }

    void build_heap() {
        for (int i = n / 2; i >= 1; i--) {
            sift(i);
        }
    }

    int left_child(int pos) {
        return (2 * pos);
    }
    int right_child(int pos) {
        return (2 * pos + 1);
    }

    int parent(int pos) {
        return pos / 2;
    }

    int is_leaf(int pos) {
        return pos > (n / 2) && pos <= n;
    }

   public:
    Heap(vector<int>& h, int size) : heap(h) {
        n = max_size = size;
        build_heap();
    }

    void push(int item) {
        int curr = ++n;
        heap[curr] = item;
        while ((curr != 1) && heap[curr] < heap[parent(curr)]) {  // bubble up if child is greater than parent.
            swap(heap[curr], heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    int pop() {  // remove root node
        if (n == 0) {
            return 100001;
        }
        swap(heap[1], heap[n--]);
        int temp = heap[n + 1];
        sift(1);
        return temp;
    };

    int size() {
        return n;
    }
};

int main() {
    int tc;
    while (cin >> tc && tc != 0) {
        vector<int> t(tc + 1);
        for (int i = 1; i <= tc; i++) {
            cin >> t[i];
        }
        auto h = new Heap(t, tc);
        int total = 0;
        int cost = 0;
        while (h->size() > 1) {
            int i = h->pop();
            int j = h->pop();
            cost = i + j;
            total += cost;
            h->push(cost);
        }
        cout << total << '\n';
    }
    return 0;
}
