#include <iostream>
#include <vector>

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
    K* heap;
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
            swap(heap, pos, j);  // sift down
            pos = j;             // do it until element at pos is in the right place.
        }
    }

    void build_heap() {
        for (int i = (n / 2 - 1); i >= 0; i--) {
            sift_down(i);
        }
    }

   public:
    Heap(K* h, int maxs, int curr_size) {
        heap = h;
        max_size = maxs;
        n = curr_size;
        build_heap();
    }

    int left_child(int pos) {
        return (2 * pos + 1);
    }
    int right_child(int pos) {
        return (2 * pos + 2);
    }

    int parent(int pos) {
        return (pos - 1) / 2;
    }

    int is_leaf(int pos) {
        return pos >= (n / 2) && pos < n;
    }

    void insert(K& item) {
        int curr = n++;
        heap[curr] = item;
        while ((curr != 1) && heap[curr] >= heap[parent(curr)]) {  // bubble up  if child is greather than parent.
            swap(heap, curr, parent(curr));
            curr = parent(curr);
        }
    }
};

int main() {
    vector<int> items = {0, 2, 9, 7, 6, 5, 8, 10};

    return 0;
}