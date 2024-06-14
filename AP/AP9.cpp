#include <iostream>
using namespace std;

class Heap {
    int *heap;
    int max_size;
    int n;

    void sift_down(int pos) {
        while (!is_leaf(pos)) {
            int j = left_child(pos), rc = right_child(pos);
            if ((rc <= n) && heap[rc] >= heap[j]) {
                j = rc;
            }
            if (heap[pos] >= heap[j]) {
                return;
            }
            swap(heap[pos], heap[j]);
            pos = j;
        }
    };

    void build_heap() {
        for (int i = n / 2; i >= 1; i--) {
            int k = i;
            int v = heap[k];
            int is_heap = false;
            while (!is_heap && left_child(k) <= n) {
                int j = left_child(k);
                if (j < n) {
                    if (heap[j] < heap[j + 1]) {
                        // j = right_child(k);
                        j++;
                    }
                }

                if (v >= heap[j]) {
                    is_heap = true;
                } else {
                    heap[k] = heap[j];
                    k = j;
                }
            }
            heap[k] = v;
        }
    }

   public:
    Heap(int *h, int maxs, int heap_size) : heap(h), max_size(maxs), n(heap_size) {
        build_heap();
    }
    int left_child(int pos) {
        return 2 * pos;
    }
    int right_child(int pos) {
        return 2 * pos + 1;
    }
    int parent(int pos) {
        return pos / 2;
    }
    int is_leaf(int pos) {
        return pos > n / 2 && pos <= n;
    }

    void push(int item) {
        int curr = n++;
        heap[curr] = item;
        while ((curr != 1) && heap[curr] >= heap[parent(curr)]) {
            swap(heap[curr], heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    int pop() {
        if (n == 0) {
            return 0;
        }

        swap(heap[1], heap[n--]);
        sift_down(1);
        return heap[n + 1];
    }
};

void heap_sort(int *arr, int size) {
    // int buf[size + 1];
    // memcpy(buf + 1, arr, sizeof(buf) - 1);
    auto h = new Heap(arr, size + 1, size);
    for (int i = 0; i < size - 1; i++) {
        h->pop();
    }
    // memcpy(arr, buf + 1, sizeof(buf) - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    heap_sort(arr, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}