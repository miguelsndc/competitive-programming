#include <bits/stdc++.h>

#include <iostream>

using namespace std;

/*
Heap ADT
- push()
    Inserts the new key after the last leaf of the heap
    Heapify the key until dominance is satisfied
- pop()
    Exchange root with the last key of the heap, decrease size
    by 1, get rid of the old root then heapify the tree by shifting
    the new root down until dominance is satisfied
- top()
    peek the root element
- private:
- heapify()
    does the heapifying stuff
*/

// K - comparable, orderable;
template <typename K>
class Heap {
   private:
    vector<K>& heap;
    int max_size;
    int n;

    void sift_down(int pos) {
        while (!is_leaf(pos)) {
            int j = left_child(pos), rc = right_child(pos);
            if ((rc < n) && heap[rc] >= heap[j]) {
                j = rc;
            }
            if (heap[pos] >= heap[j]) {
                return;  // is heap
            }
            swap(heap[pos], heap[j]);  // sift down
            pos = j;                   // do it until element at pos is in the right place.
        }
    }

    void build_heap() {
        for (int i = n / 2; i >= 1; i--) {
            int k = i;
            K v = heap[k];
            int is_heap = false;
            while (!is_heap && left_child(k) <= n) {
                int j = left_child(k);
                if (j < n) {
                    if (heap[j] < heap[j + 1]) {  // right child is greater
                        j = right_child(k);
                    }
                }

                if (v >= heap[j]) {  // heap property ok
                    is_heap = true;
                } else {
                    heap[k] = heap[j];
                    k = j;
                }
            }
            heap[k] = v;
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
        return pos > (n / 2) && pos < n;
    }

   public:
    Heap(vector<K>& h, int maxs, int curr_size) : heap(h) {
        max_size = maxs;
        n = curr_size;
        build_heap();
    }

    void push(K item) {
        int curr = n++;
        heap[curr] = item;
        while ((curr != 1) && heap[curr] >= heap[parent(curr)]) {  // bubble up  if child is greather than parent.
            swap(heap[curr], heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    K pop() {  // remove root node
        if (n == 0) {
            return K();
        }
        swap(heap[1], heap[n--]);
        K temp = heap[n + 1];
        sift_down(1);
        return temp;
    };
};

int main() {
    vector<int> arr = {9, 7, 6, 8, 4, 5, 3, 2, 1, 6, 45, 9};
    auto h = new Heap<int>(arr, arr.size(), 6);

    h->push(12);
    h->pop();
}